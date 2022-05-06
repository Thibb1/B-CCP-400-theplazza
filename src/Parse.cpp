/*
** EPITECH PROJECT, 2022
** Parse.cpp
** File description:
** TODO
*/

#include "Parse.hpp"

Parse::Parse(int ac, char **av)
{
    CheckArguments(ac, av);
}

void Parse::CheckArguments(int ac, char **av)
{
    char *ptr;

    if (ac != 4)
        throw PlazzaUsageError();
    CookingTime = strtod(av[1], &ptr);
    if (av[1] == ptr || CookingTime < 0)
        throw PlazzaUsageError();
    Cooks = strtol(av[2], &ptr, 10);
    if (av[2] == ptr || Cooks < 0)
        throw PlazzaUsageError();
    RefillTime = strtol(av[3], &ptr, 10);
    if (av[3] == ptr || RefillTime < 0)
        throw PlazzaUsageError();
}