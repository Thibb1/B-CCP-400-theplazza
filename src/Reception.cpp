/*
** EPITECH PROJECT, 2022
** Reception.cpp
** File description:
** TODO
*/

#include "Reception.hpp"

namespace plazza {

void Reception::run()
{
    std::cout << "> ";
    std::string line;
    while (getline(std::cin, line)) {
        bool error = ParseCommand(line);
        if (RegUtils::isMatch(line, "QUIT", std::regex::icase)) {
            return;
        } else if (error) {
            std::cout << "ERROR: Wrong pizza command" << std::endl;
        }
        std::cout << "> ";
    }
}

bool Reception::ParseCommand(const std::string& line) {
    std::string input = RegUtils::removeSpaces(line);
    stringV commands = RegUtils::split(input, "; ?");

    if (commands.empty())
        return true;

    for (auto &command : commands) {

        if (command.empty())
            return true;

        stringV orders = RegUtils::split(command, " ");

        if (orders.size() != 3)
            return true;

        if (!RegUtils::isMatch(orders[0], "Regina|Margarita|Americana|Fantasia", std::regex::icase)
            || !RegUtils::isMatch(orders[1], "S|M|L|XL|XXL")
            || !RegUtils::isMatch(orders[2], "x[1-9]\\d*"))
            return true;

        std::string number = RegUtils::getMatch(orders[2], "x([1-9]\\d*)")[1];

        StartReception(orders[0], orders[1], number);
    }
    return false;
}

void Reception::StartReception(const std::string &pizza,
                          const std::string &size, const std::string &number)
{
    std::cout << "Pizza: " << pizza << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Number: " << number << std::endl;
}

}