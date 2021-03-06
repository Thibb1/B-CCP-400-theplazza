/*
** EPITECH PROJECT, 2022
** Parse.hpp
** File description:
** parse program arguments
*/

#pragma once

#include "Exceptions.hpp"

namespace plazza {
    class Parse {
    protected:
        double CookingTime{};
        long Cooks{};
        long RefillTime{};
    public:
        Parse(int ac, char **av);

        virtual ~Parse() = default;

        void CheckArguments(int ac, char **av);
    };
}