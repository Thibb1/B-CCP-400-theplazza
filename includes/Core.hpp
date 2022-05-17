/*
** EPITECH PROJECT, 2022
** Core.hpp
** File description:
** Manager for threads and reception
*/

#pragma once

#include <memory>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <array>
#include "Pizza.hpp"
#include "ThreadPool.hpp"

namespace plazza
{
    typedef std::shared_ptr<IPizza> sPizza;
    typedef std::shared_ptr<bool> sBool;
    typedef std::chrono::system_clock sysClock;

    class Reception
    {
    public:
        Reception() = default;
        ~Reception() = default;
        mutable std::mutex mMutex;
        std::vector<sPizza> pizzaIn{};
        std::vector<sPizza> pizzaOut{};
    };

    class Orders
    {
    public:
        Orders() = default;
        ~Orders() = default;
        void push(const sPizza &pizza)
        {
            mMutex.lock();
            pizzaBuffer.push_back(pizza);
            mMutex.unlock();
            nbCooks++;
        };
        std::atomic<int> nbCooks{};
        mutable std::mutex mMutex{};
        std::vector<sPizza> pizzaBuffer{};
        std::array<std::atomic<int>, 9> ingredients{5, 5, 5, 5, 5, 5, 5, 5, 5};
    };

    typedef std::shared_ptr<Orders> sOrders;
    class Core
    {
    private:
        Reception mReception{};
        ThreadPool threads{};
        std::vector<sBool> mKitchensAlive{};
        std::vector<sOrders> vOrders{};
    public:
        Core() = default;
        ~Core() = default;
        void addPizza(const sPizza &pizza);
        void start(double multiplier, long cooks, long replaceTime);
        void loop();

        [[nodiscard]] inline const auto &getReception() const noexcept {return mReception;};
        [[nodiscard]] inline const auto &getOrders() const noexcept {return vOrders;};

        [[noreturn]] static void ThreadManager(Reception &reception, ThreadPool &pool, std::vector<sOrders> &database, std::mutex &dbMutex, std::vector<sBool> &kitchensAlive);
        [[noreturn]] static void IngredientManager(std::vector<sOrders> &kitchenOrders, std::mutex &dbMutex);
        static int emptiestKitchen(std::vector<sOrders> &database);

        static double mMultiplier;
        static long mCooks;
        static long mReplaceTime;

        mutable std::mutex mDbMutex{};

        void addOrderToKitchen(sPizza &pizza);
    };

    void kitchenThread(const sBool& alive, plazza::Reception &reception, sOrders orders);
    void cookThread(const sBool& alive, plazza::Reception &reception, const sOrders& database, const sPizza& pizza);
}