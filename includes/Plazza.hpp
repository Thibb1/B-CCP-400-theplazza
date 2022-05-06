/*
** EPITECH PROJECT, 2022
** Plazza.hpp
** File description:
** TODO
*/

#pragma once

#include <string>
#include <regex>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "PlazzaError.hpp"
#include "RegexUtils.hpp"

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

#define MATCH "(?: *([[:alpha:]]+) (S|M|L|XL|XXL) x(\\d+))"
#define EXIT_ERROR 84