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
        bool ParseCommand(const std::string& line);
        static void StartReception(const std::string& pizza, const std::string& size, const std::string& number);
        void run();
};

}
