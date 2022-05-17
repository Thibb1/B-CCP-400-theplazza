/*
** EPITECH PROJECT, 2022
** Core.cpp
** File description:
** Manager for threads and reception
*/

#include "Core.hpp"
#include "Logger.hpp"

namespace plazza {
    double Core::mCoookingTime = 0;
    long Core::mCooks = 0;
    long Core::mRefillTime = 0;

    void Core::addPizza(const sPizza &pizza) {
        mReception.mMutex.lock();
        mReception.pizzaIn.push_back(pizza);
        mReception.mMutex.unlock();
    }

    void Core::start(double cookingTime, long cooks, long refillTime) {
        mCoookingTime = cookingTime;
        mCooks = cooks;
        mRefillTime = refillTime;

        std::thread threadManager(ThreadManager, std::ref(mReception), std::ref(threads), std::ref(vOrders),
                                  std::ref(mDbMutex), std::ref(mKitchensAlive));
        threadManager.detach();
        std::thread ingredientsManager(IngredientManager, std::ref(vOrders), std::ref(mDbMutex));
        ingredientsManager.detach();
    }

    inline int Core::emptiestKitchen(std::vector<sOrders> &database) {
        int smallest = int(Core::mCooks);

        for (const auto &kitchen: database)
            if (kitchen->nbCooks < smallest)
                smallest = kitchen->nbCooks;
        return smallest;
    }

    void Core::run() {
        mReception.mMutex.lock();
        for (auto &in: mReception.pizzaIn)
            log("[RECEPTION] New order: ", revMapPizzaType[in->getType()], " ", revMapPizzaSize[in->getSize()], "\n");
        for (auto &pizza: mReception.pizzaIn)
            addOrderToKitchen(pizza);
        mReception.pizzaIn.clear();
        mReception.mMutex.unlock();
    }

    [[noreturn]] void
    Core::ThreadManager(Reception &reception, ThreadPool &pool, std::vector<sOrders> &database, std::mutex &dbMutex,
                        std::vector<sBool> &kitchensAlive) {
        using namespace std::chrono_literals;
        while (true) {
            std::this_thread::sleep_for(0.1s);
            reception.mMutex.lock();
            dbMutex.lock();
            for (size_t i = 0; i < kitchensAlive.size(); i++) {
                if (!*kitchensAlive[i]) {
                    pool.remove(i);
                    kitchensAlive.erase(kitchensAlive.begin() + long(i));
                    database.erase(database.begin() + long(i));
                    log("[THREAD] a kitchen closed (thread killed)\n");
                    i = 0;
                }
            }
            for (auto &out: reception.pizzaOut)
                log("[RECEPTION] Order ready: ", revMapPizzaType[out->getType()], " ", revMapPizzaSize[out->getSize()],
                    "\n");
            reception.pizzaOut.clear();
            reception.mMutex.unlock();
            dbMutex.unlock();
        }
    }

    [[noreturn]] void Core::IngredientManager(std::vector<sOrders> &kitchenOrders, std::mutex &dbMutex) {
        while (true) {
            std::chrono::milliseconds duration(Core::mRefillTime);
            std::this_thread::sleep_for(duration);
            for (auto &orders: kitchenOrders) {
                orders->mMutex.lock();
                dbMutex.lock();
                for (auto &ingredient: orders->ingredients)
                    ingredient += 1;
                orders->mMutex.unlock();
                dbMutex.unlock();
            }
            //log("[THREAD] ingredients updated\n");
        }
    }

    void Core::addOrderToKitchen(sPizza &pizza) {
        int smallest = emptiestKitchen(vOrders);
        for (auto &kitchen: vOrders) {
            if (kitchen->nbCooks < mCooks and (kitchen->nbCooks == 0 or kitchen->nbCooks == smallest)) {
                kitchen->push(pizza);
                return;
            }
        }
        vOrders.push_back(std::make_shared<Orders>());
        mKitchensAlive.emplace_back(std::make_shared<bool>(true));
        threads.add(kitchenThread, mKitchensAlive.back(), std::ref(mReception), vOrders.back());
        vOrders.back()->push(pizza);
    }
}