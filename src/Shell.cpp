/*
** EPITECH PROJECT, 2022
** Shell.cpp
** File description:
** reception
*/

#include <iostream>
#include "Exceptions.hpp"
#include "Shell.hpp"
#include "Pizza.hpp"
#include "Logger.hpp"
#include "RegexUtils.hpp"
#include "Mutex.hpp"

namespace plazza {
    void Shell::status() const noexcept {
        int i = 0;
        this->core.getReception().mutex.Lock();
        this->core.dbMutex.Lock();
        log("[STATUS]\nActive kitchens: ", this->core.getOrders().size(), "\n");
        for (const auto &kitchen: this->core.getOrders())
            log("  Working cooks in kitchen ", i++, ": ", int(kitchen->nbCooks), "\n");
        int j = 0;
        for (const auto &kitchen: this->core.getOrders()) {
            log("Kitchen ", j++, ":\n");
            i = 0;
            for (const auto &ingredient: kitchen->ingredients)
                log("  ", mapPizzaIngredients[i++], ": ", int(ingredient), "\n");
        }
        this->core.getReception().mutex.Unlock();
        this->core.dbMutex.Unlock();
    }

    void Shell::factory(const PizzaType &pizzaType, const PizzaSize &pizzaSize) {
        if (pizzaType == Regina)
            orderBuffer.push_back(std::make_shared<regina>(pizzaSize));
        else if (pizzaType == Margarita)
            orderBuffer.push_back(std::make_shared<margarita>(pizzaSize));
        else if (pizzaType == Americana)
            orderBuffer.push_back(std::make_shared<americana>(pizzaSize));
        else if (pizzaType == Fantasia)
            orderBuffer.push_back(std::make_shared<fantasia>(pizzaSize));
        else
            throw PlazzaBadCommand();
    }

    void Shell::run() {
        this->core.start(CookingTime, Cooks, RefillTime);
        std::cout << "> ";
        std::string line;
        while (getline(std::cin, line)) {
            if (RegUtils::isMatch(line, "QUIT", std::regex::icase)) {
                return;
            } else if (RegUtils::isMatch(line, "status", std::regex::icase)) {
                status();
            } else if (ParseCommand(line)) {
                std::cout << "ERROR: Wrong pizza command" << std::endl;
                orderBuffer.clear();
            }
            ApplyOrders();
            std::cout << "> ";
        }
    }

    bool Shell::ParseCommand(const std::string &line) {
        std::string input = RegUtils::removeSpaces(line);
        vString commands = RegUtils::split(input, "; ?");

        if (commands.empty())
            return true;

        for (auto &command: commands) {

            if (command.empty())
                return true;

            vString orders = RegUtils::split(command, " ");

            if (orders.size() != 3)
                return true;

            if (!RegUtils::isMatch(orders[0], "Regina|Margarita|Americana|Fantasia", std::regex::icase) ||
                !RegUtils::isMatch(orders[1], "S|M|L|XL|XXL") || !RegUtils::isMatch(orders[2], "x[1-9]\\d*"))
                return true;

            std::string number = RegUtils::getMatch(orders[2], "x([1-9]\\d*)")[1];

            AddOrder(orders[0], orders[1], std::stoi(number));
        }
        return false;
    }

    void Shell::AddOrder(std::string pizza, const std::string &size, int number) {
        std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
        for (int i = 0; i < number; i++)
            factory(mapPizzaType[pizza], mapPizzaSize[size]);
    }

    void Shell::ApplyOrders() {
        for (auto &pizza: orderBuffer)
            this->core.addPizza(pizza);
        orderBuffer.clear();
        this->core.run();
    }
}