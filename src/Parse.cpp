/*
** EPITECH PROJECT, 2022
** Parse.cpp
** File description:
** TODO
*/

#include "Parse.hpp"

Parse::Parse(int NbArguments, char **Arguments)
{
    CheckArguments(NbArguments, Arguments);
}

void Parse::CheckArguments(int NbArguments, char **Arguments)
{
    char *Ptr;

    if (NbArguments != 4)
        throw PlazzaUsageError();
    CookingTime = strtod(Arguments[1], &Ptr);
    if (Arguments[1] == Ptr || CookingTime < 0)
        throw PlazzaUsageError();
    Cooks = strtol(Arguments[2], &Ptr, 10);
    if (Arguments[2] == Ptr || Cooks < 0)
        throw PlazzaUsageError();
    RefillTime = strtol(Arguments[3], &Ptr, 10);
    if (Arguments[3] == Ptr || RefillTime < 0)
        throw PlazzaUsageError();
}