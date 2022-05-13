/*
** EPITECH PROJECT, 2022
** Reception.hpp
** File description:
** Reception
*/

#pragma once

#include "Parse.hpp"
#include "RegexUtils.hpp"
#include "Kitchen.hpp"

namespace plazza {

class Reception : public Parse {
    public:
        Reception(int ac, char **av) : Parse(ac, av) {}
        bool ParseCommand(const std::string& line);
        static void StartReception(std::string pizza, std::string size, const std::string& number);
        void run();
        static void SendPizzaToKitchen(Pizza pizza);
        void PrintKitchenStatus();

        static int GetFreeKitchen();

        int GetNewKitchen();

    private:
        int kitchens{};
};

}
