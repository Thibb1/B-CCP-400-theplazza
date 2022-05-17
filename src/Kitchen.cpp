/*
** EPITECH PROJECT, 2022
** Kitchen.cpp
** File description:
** cook thread and kitchen thread
*/

#include "Core.hpp"
#include <chrono>

using namespace std::chrono_literals;

bool enoughIngredients(const plazza::sOrders &orders, const plazza::sPizza &pizza) {
    std::scoped_lock scopedLock(orders->mMutex);
    for (const auto &ingredient: pizza->getIngredients())
        if (orders->ingredients[int(ingredient)] <= 0)
            return false;
    for (const auto &ingredient: pizza->getIngredients())
        orders->ingredients[int(ingredient)] -= 1;
    return true;
}

namespace plazza {
    void cookThread(const sBool &alive, Reception &reception, const sOrders &database, const sPizza &pizza) {
        auto cookingTime = float(pizza->getCookingTime());

        while (!enoughIngredients(database, pizza));

        sysClock::time_point deadline =
                sysClock::now() + std::chrono::microseconds(int(Core::mMultiplier * 1000000 * cookingTime));
        while (sysClock::now() < deadline);
        reception.mMutex.lock();
        reception.pizzaOut.push_back(pizza);
        reception.mMutex.unlock();
        database->nbCooks--;
        *alive = false;
    }

    void kitchenThread(const sBool &alive, Reception &reception, sOrders orders) {
        ThreadPool cooks;
        std::vector<sBool> cooksStatus;
        sysClock::time_point deadline = sysClock::now() + std::chrono::seconds(5);
        while (true) {
            if (sysClock::now() >= deadline) {
                cooks.release();
                *alive = false;
                return;
            }
            orders->mMutex.lock();
            if (!orders->pizzaBuffer.empty()) {
                deadline = sysClock::now() + std::chrono::seconds(5);
                auto pizza = orders->pizzaBuffer.back();
                orders->pizzaBuffer.pop_back();
                cooksStatus.emplace_back(std::make_shared<bool>(true));
                cooks.add(cookThread, cooksStatus.back(), std::ref(reception), orders, pizza);
            }
            orders->mMutex.unlock();
            for (size_t i = 0; i < cooksStatus.size(); i++) {
                if (!*cooksStatus[i]) {
                    deadline = sysClock::now() + std::chrono::seconds(5);
                    cooks.remove(i);
                    cooksStatus.erase(cooksStatus.begin() + long(i));
                }
            }
        }
    }
}