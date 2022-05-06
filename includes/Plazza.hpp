/*
** EPITECH PROJECT, 2022
** Plazza.hpp
** File description:
** default includes
*/

#pragma once

#include <string>
#include <regex>
#include <iostream>

#include "RegexUtils.hpp"
#include "Pizza.hpp"

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