/*
** EPITECH PROJECT, 2022
** Reception.hpp
** File description:
** TODO
*/

#pragma once
#include "Parse.hpp"

class Reception : public Parse {
public:
    Reception(int ac, char **av) : Parse(ac, av) {}
    ~Reception() = default;
    void run();
};
