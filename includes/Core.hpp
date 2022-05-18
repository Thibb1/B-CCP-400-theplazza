/*
** EPITECH PROJECT, 2022
** Core.hpp
** File description:
** Manager for threads and reception
*/

#pragma once

#include <memory>
#include <vector>
#include <thread>
#include <atomic>
#include <array>
#include "Pizza.hpp"
#include "ThreadPool.hpp"
#include "Mutex.hpp"

namespace plazza {

class Reception {
    public:
        Reception() = default;
        ~Reception() = default;
        Mutex mutex;
        std::vector<std::shared_ptr<IPizza>> pizzaIn{};
        std::vector<std::shared_ptr<IPizza>> pizzaOut{};
};

class Orders {
    public:
        Orders() = default;
        ~Orders() = default;

        void push(const std::shared_ptr<IPizza> &pizza) {
            mutex.Lock();
            pizzaBuffer.push_back(pizza);
            mutex.Unlock();
            nbCooks++;
        };
        std::atomic<int> nbCooks{};
        Mutex mutex{};
        std::vector<std::shared_ptr<IPizza>> pizzaBuffer{};
        std::array<std::atomic<int>, 9> ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5};
};

class Core {
    private:
        Reception reception{};
        ThreadPool threads{};
        std::vector<std::shared_ptr<bool>> mKitchensAlive{};
        std::vector<std::shared_ptr<Orders>> vOrders{};

    public:
        Core() = default;
        ~Core() = default;
        void addPizza(const std::shared_ptr<IPizza> &pizza);
        void start(double cookingTime, long cooks, long refillTime);
        void run();
        [[nodiscard]] inline const auto &getReception() const noexcept { return this->reception; };
        [[nodiscard]] inline const auto &getOrders() const noexcept { return vOrders; };
        [[noreturn]] static void ThreadManager(Reception &reception, ThreadPool &pool, std::vector<std::shared_ptr<Orders>> &database, std::mutex &dbMutex, std::vector<std::shared_ptr<bool>> &kitchensAlive);
        [[noreturn]] static void IngredientManager(std::vector<std::shared_ptr<Orders>> &kitchenOrders, std::mutex &dbMutex);
        static int emptiestKitchen(std::vector<std::shared_ptr<Orders>> &database);
        static double CoookingTime;
        static long Cooks;
        static long RefillTime;
        Mutex dbMutex{};
        void addOrderToKitchen(std::shared_ptr<IPizza> &pizza);
};

void kitchenThread(const std::shared_ptr<bool> &alive, plazza::Reception &reception, std::shared_ptr<Orders> orders);
void cookThread(const std::shared_ptr<bool> &alive, plazza::Reception &reception, const std::shared_ptr<Orders> &database, const std::shared_ptr<IPizza> &pizza);

}