/*
** EPITECH PROJECT, 2022
** Parse.cpp
** File description:
** TODO
*/

#include "Parse.hpp"

Parse::Parse(int NbArguments, char **Arguments)
{
    
}

int Parse::CheckArguments(int NbArguments, char **Arguments)
{
    char *Ptr;

    if (NbArguments != 4)
        throw PlazzaUsageError();
    CookingTime = strtod(Arguments[1], &Ptr);
    if (Arguments[1] == Ptr)
        throw PlazzaUsageError();
    Cooks = strtol(Arguments[2], &Ptr, 10);
    if (Arguments[2] == Ptr)
        throw PlazzaUsageError();
    RefillTime = strtol(Arguments[3], &Ptr, 10);
    if (Arguments[3] == Ptr)
        throw PlazzaUsageError();
}