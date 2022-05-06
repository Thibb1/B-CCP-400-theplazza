/*
** EPITECH PROJECT, 2022
** Reception.hpp
** File description:
** Reception
*/

#pragma once

#include "Parse.hpp"
#include "RegexUtils.hpp"

namespace plazza {

class Reception : public Parse {
    public:
        Reception(int ac, char **av) : Parse(ac, av) {}

        void checkType(PizzaType type);
        void run();
};

}
