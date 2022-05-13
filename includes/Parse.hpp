/*
** EPITECH PROJECT, 2022
** Parse.hpp
** File description:
** TODO
*/

#pragma once

#include "Plazza.hpp"

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
