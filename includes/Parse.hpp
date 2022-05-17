/*
** EPITECH PROJECT, 2022
** TODO.hpp
** File description:
** TODO
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