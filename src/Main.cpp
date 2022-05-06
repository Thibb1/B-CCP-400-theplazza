/*
** EPITECH PROJECT, 2022
** Main.cpp
** File description:
** main
*/

#include "Plazza.hpp"
#include "Reception.hpp"

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