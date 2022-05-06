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
        line = RegUtils::removeSpaces(line);
        std::cout << "typed: '" << line << "'";
        if (RegUtils::isMatch(line, MATCH)) {
        //    stringV elems = RegUtils::getMatch(line, MATCH);
        //for (const auto& elem : RegUtils::getMatch(line, MATCH)) {
        //    std::cout << "|" << elem << "|";
        //}
        //for (const auto& elem : RegUtils::getSmatch(line, MATCH)) {
        //    std::cout << "|" << elem.str() << "|";
        //}
            std::cout << "Matched" << std::endl;
        } else if (RegUtils::isMatch(line, "QUIT")) {
            return;
        } else {
            std::cout << "ERROR: Wrong pizza command" << std::endl;
        }
        std::cout << "> ";
    }
}

}