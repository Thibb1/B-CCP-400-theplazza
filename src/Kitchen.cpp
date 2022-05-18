/*
** EPITECH PROJECT, 2022
** Kitchen.cpp
** File description:
** cook thread and kitchen thread
*/

#include <chrono>
#include "Core.hpp"
#include "Mutex.hpp"

using namespace std::chrono_literals;
bool enoughIngredients(const std::shared_ptr<plazza::Orders> &orders, const std::shared_ptr<plazza::IPizza> &pizza) {
    std::scoped_lock scopedLock(orders->mutex);

    for (const auto &ingredient: pizza->getIngredients())
        if (orders->ingredients[int(ingredient)] <= 0)
            return false;

    for (const auto &ingredient: pizza->getIngredients())
        orders->ingredients[int(ingredient)] -= 1;

    return true;
}

namespace plazza {
    void cookThread(const std::shared_ptr<bool> &alive, Reception &reception, const std::shared_ptr<Orders> &database, const std::shared_ptr<IPizza> &pizza) {
        auto cookingTime = float(pizza->getCookingTime());

        while (!enoughIngredients(database, pizza));

        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::microseconds(int(Core::CoookingTime * 1000000 * cookingTime));
        while (std::chrono::system_clock::now() < deadline);
        reception.mutex.Lock();
        reception.pizzaOut.push_back(pizza);
        reception.mutex.Unlock();
        database->nbCooks--;
        *alive = false;
    }

    void kitchenThread(const std::shared_ptr<bool> &alive, Reception &reception, std::shared_ptr<Orders> orders) {
        ThreadPool cooks;
        std::vector<std::shared_ptr<bool>> cooksStatus;
        std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::seconds(5);
        while (true) {
            if (std::chrono::system_clock::now() >= deadline) {
                cooks.release();
                *alive = false;
                return;
            }
            orders->mutex.Lock();
            if (!orders->pizzaBuffer.empty()) {
                deadline = std::chrono::system_clock::now() + std::chrono::seconds(5);
                auto pizza = orders->pizzaBuffer.back();
                orders->pizzaBuffer.pop_back();
                cooksStatus.emplace_back(std::make_shared<bool>(true));
                cooks.add(cookThread, cooksStatus.back(), std::ref(reception), orders, pizza);
            }
            orders->mutex.Unlock();
            for (size_t i = 0; i < cooksStatus.size(); i++) {
                if (!*cooksStatus[i]) {
                    deadline = std::chrono::system_clock::now() + std::chrono::seconds(5);
                    cooks.remove(i);
                    cooksStatus.erase(cooksStatus.begin() + long(i));
                }
            }
        }
    }
}