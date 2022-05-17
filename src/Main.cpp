/*
** EPITECH PROJECT, 2022
** Main.cpp
** File description:
** main
*/

#include <iostream>
#include "Exceptions.hpp"
#include "Shell.hpp"

int main(int ac, char **av) {
    try {
        plazza::Shell app(ac, av);
        app.run();
    } catch (const plazza::PlazzaError &error) {
        std::cerr << error.what() << std::endl;
        return EXIT_ERROR;
    } catch (const std::exception &exception) {
        std::cerr << exception.what() << std::endl;
        return EXIT_ERROR;
    } catch (...) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}