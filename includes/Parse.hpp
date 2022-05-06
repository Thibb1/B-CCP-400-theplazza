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
        float CookingTime;
        int Cooks;
        int RefillTime;

    public:
        Parse(int NbArguments, char **Arguments);
        virtual ~Parse() = default;
        int CheckArguments(int NbArguments, char **Arguments);
};
