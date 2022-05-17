/*
** EPITECH PROJECT, 2022
** Shell.hpp
** File description:
** Orders manager
*/

#pragma once

#include <string_view>
#include <vector>
#include <memory>
#include "Core.hpp"
#include "Parse.hpp"

namespace plazza {
    class Shell : public Parse {
    private:
        Core mCore{};
        std::vector<sPizza> orderBuffer{};
    public:
        Shell(int ac, char **av) : Parse(ac, av) {};

        ~Shell() override = default;

        void run();

        void status() const noexcept;

        void factory(const PizzaType &pizzaType, const PizzaSize &pizzaSize);

        bool ParseCommand(const std::string &line);

        void AddOrder(std::string pizza, const std::string &size, int number);

        void ApplyOrders();
    };
}