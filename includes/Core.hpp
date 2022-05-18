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
    typedef std::shared_ptr<IPizza> sPizza;
    typedef std::shared_ptr<bool> sBool;
    typedef std::chrono::system_clock sysClock;

    class Reception {
    public:
        Reception() = default;

        ~Reception() = default;

        mutable Mutex mutex;
        std::vector<sPizza> pizzaIn{};
        std::vector<sPizza> pizzaOut{};
    };

    class Orders {
    public:
        Orders() = default;

        ~Orders() = default;

        void push(const sPizza &pizza) {
            mutex.Lock();
            pizzaBuffer.push_back(pizza);
            mutex.Unlock();
            nbCooks++;
        };
        std::atomic<int> nbCooks{};
        Mutex mutex{};
        std::vector<sPizza> pizzaBuffer{};
        std::array<std::atomic<int>, 9> ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5};
    };

    typedef std::shared_ptr<Orders> sOrders;

    class Core {
    private:
        Reception reception{};
        ThreadPool threads{};
        std::vector<sBool> mKitchensAlive{};
        std::vector<sOrders> vOrders{};

    public:
        Core() = default;

        ~Core() = default;

        void addPizza(const sPizza &pizza);

        void start(double cookingTime, long cooks, long refillTime);

        void run();

        [[nodiscard]] inline const auto &getReception() const noexcept { return this->reception; };

        [[nodiscard]] inline const auto &getOrders() const noexcept { return vOrders; };

        [[noreturn]] static void
        ThreadManager(Reception &reception, ThreadPool &pool, std::vector<sOrders> &database,
                      Mutex &dbMutex, std::vector<sBool> &kitchensAlive);

        [[noreturn]] static void IngredientManager(std::vector<sOrders> &kitchenOrders, Mutex &dbMutex);

        static int emptiestKitchen(std::vector<sOrders> &database);

        static double CookingTime;
        static long Cooks;
        static long RefillTime;
        mutable Mutex dbMutex{};

        void addOrderToKitchen(sPizza &pizza);
    };

    void
    kitchenThread(const sBool &alive, plazza::Reception &reception, sOrders orders);

    void cookThread(const sBool &alive, plazza::Reception &reception,
                    const sOrders &database, const sPizza &pizza);

}