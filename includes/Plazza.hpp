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
#include <thread>
#include <boost/regex.hpp>

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

#define MATCH "((?i)regina|margarita|americana|fantasia) (XXL|XL|X|M|S) x([1-9]\\d*)"
#define EXIT_ERROR 84