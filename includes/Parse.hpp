/*
** EPITECH PROJECT, 2022
** Parse.hpp
** File description:
** TODO
*/

#pragma once

#include "Plazza.hpp"

class Parse {

    public:
        double CookingTime;
        long Cooks;
        long RefillTime;

    public:
        Parse(int NbArguments, char **Arguments);
        virtual ~Parse() = default;
        void CheckArguments(int NbArguments, char **Arguments);
};
