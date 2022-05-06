/*
** EPITECH PROJECT, 2022
** Plazza.hpp
** File description:
** TODO
*/

#pragma once

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <boost/regex.hpp>

#include "PlazzaError.hpp"
#include "RegexUtils.hpp"
#include "Pizza.hpp"

#define MATCH "((?i)regina|margarita|americana|fantasia) (XXL|XL|X|M|S) x([1-9]\\d*)"
#define EXIT_ERROR 84

namespace plazza {

class Plazza {
    private:
        float cookingTime;
        uint32_t nbCooks;
        uint32_t time;
    public:
        Plazza(float cookingTime, uint32_t nbCooks, uint32_t time);
};

}
