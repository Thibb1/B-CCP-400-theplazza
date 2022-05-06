/*
** EPITECH PROJECT, 2022
** Reception.cpp
** File description:
** TODO
*/

#include "Reception.hpp"

void Reception::run()
{
    std::cout << "> ";
    std::string line;
    while (getline(std::cin, line)) {
        line = RegUtils::removeSpaces(line);
        if (RegUtils::isMatch(line, MATCH)) {
            stringV elems = RegUtils::getMatch(line, MATCH);
            for (const auto& elem : elems) {
                std::cout << "|" << elem << "|";
            }
            std::cout << "Matched" << std::endl;
        } else if (RegUtils::isMatch(line, "QUIT")) {
            return;
        } else {
            std::cout << "ERROR: Wrong pizza command" << std::endl;
        }
        std::cout << "> ";
    }
}