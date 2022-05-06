/*
** EPITECH PROJECT, 2022
** Main.cpp
** File description:
** main
*/

#include "Plazza.hpp"
#include "Reception.hpp"

void readline()
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

int main(int ac, char **av)
{
    try {
        Reception reception(ac, av);
        reception.run();
    } catch (PlazzaError &Error) {
        std::cout << Error.what() << std::endl;
        return EXIT_ERROR;
    } catch(std::exception &Error) {
        std::cout << "The Plazza terminated with an unhandled exception:\n"
            << Error.what() << std::endl;
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}