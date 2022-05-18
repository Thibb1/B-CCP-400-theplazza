/*
** EPITECH PROJECT, 2022
** Core.cpp
** File description:
** Manager for threads and reception
*/

#include "Core.hpp"
#include "Logger.hpp"
#include "Mutex.hpp"

namespace plazza {

    double Core::CookingTime = 0;
    long Core::Cooks = 0;
    long Core::RefillTime = 0;

    void Core::addPizza(const sPizza &pizza) {
        this->reception.mutex.Lock();
        this->reception.pizzaIn.push_back(pizza);
        this->reception.mutex.Unlock();
    }

    void Core::start(double cookingTime, long cooks, long refillTime) {
        CookingTime = cookingTime;
        Cooks = cooks;
        RefillTime = refillTime;

        std::thread threadManager(ThreadManager, std::ref(reception), std::ref(threads), std::ref(vOrders), std::ref(dbMutex), std::ref(mKitchensAlive));
        threadManager.detach();
        std::thread ingredientsManager(IngredientManager, std::ref(vOrders), std::ref(dbMutex));
        ingredientsManager.detach();
    }

    inline int Core::emptiestKitchen(std::vector<sOrders> &database) {
        int smallest = int(Core::Cooks);

        for (const auto &kitchen: database) {
            if (kitchen->nbCooks < smallest) {
                smallest = kitchen->nbCooks;
            }
        }
        return smallest;
    }

    void Core::run() {
        this->reception.mutex.Lock();
        for (auto &in: this->reception.pizzaIn) {
            log("Reception> New order: ", revMapPizzaType[in->getType()], " ", revMapPizzaSize[in->getSize()], "\n");
        }
        for (auto &pizza: this->reception.pizzaIn) {
            addOrderToKitchen(pizza);
        }
        this->reception.pizzaIn.clear();
        this->reception.mutex.Unlock();
    }

    [[noreturn]] void
    Core::ThreadManager(Reception &reception, ThreadPool &pool, std::vector<sOrders> &database, Mutex &dbMutex, std::vector<sBool> &kitchensAlive) {
        using namespace std::chrono_literals;

        while (true) {
            std::this_thread::sleep_for(0.1s);
            reception.mutex.Lock();
            dbMutex.Lock();
            for (size_t i = 0; i < kitchensAlive.size(); i++) {
                if (!*kitchensAlive[i]) {
                    pool.remove(i);
                    kitchensAlive.erase(kitchensAlive.begin() + long(i));
                    database.erase(database.begin() + long(i));
                    log("Thread Manager> a kitchen has been closed\n");
                    i = 0;
                }
            }
            for (auto &out: reception.pizzaOut) {
                log("Reception> Order ready: ", revMapPizzaType[out->getType()], " ", revMapPizzaSize[out->getSize()], "\n");
            }
            reception.pizzaOut.clear();
            reception.mutex.Unlock();
            dbMutex.Unlock();
        }
    }

    [[noreturn]] void Core::IngredientManager(std::vector<sOrders> &kitchenOrders, Mutex &dbMutex) {
        while (true) {
            std::chrono::milliseconds duration(Core::RefillTime);
            std::this_thread::sleep_for(duration);

            for (auto &orders: kitchenOrders) {
                orders->mutex.Lock();
                dbMutex.Lock();
                for (auto &ingredient: orders->ingredients)
                    ingredient += 1;
                orders->mutex.Unlock();
                dbMutex.Unlock();
            }
        }
    }

    void Core::addOrderToKitchen(sPizza &pizza) {
        int smallest = emptiestKitchen(vOrders);

        for (auto &kitchen: vOrders) {
            if (kitchen->nbCooks < Cooks && (kitchen->nbCooks == 0 || kitchen->nbCooks == smallest)) {
                kitchen->push(pizza);
                return;
            }
        }
        vOrders.push_back(std::make_shared<Orders>());
        mKitchensAlive.emplace_back(std::make_shared<bool>(true));
        threads.add(kitchenThread, mKitchensAlive.back(), std::ref(this->reception), vOrders.back());
        vOrders.back()->push(pizza);
    }

}