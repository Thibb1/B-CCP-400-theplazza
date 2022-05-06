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
            std::smatch elems = RegUtils::getMatch(line, MATCH);
            for (auto elem : elems) {
                std::cout << elem.str() << " ";
            }
            std::cout << "Matched" << std::endl;
        } else if (RegUtils::isMatch(line, "QUIT")) {
            return;
        } else {
            std::cout << "Wrong typo" << std::endl;
        }
        std::cout << "> ";
    }
}
