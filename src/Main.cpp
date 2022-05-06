/*
** EPITECH PROJECT, 2022
** Main.cpp
** File description:
** main
*/

#include "Plazza.hpp"
#include <stdexcept>

int main(int ac, char **av)
{
    float cookingTime;
    int nbCooks;
    int time;

    try {
        cookingTime = std::stof(av[1]);
        nbCooks = std::stoi(av[2]);
        time = std::stoi(av[3]);
    } catch(const std::exception &exception) {
        std::cerr << "Plazza terminated with an exception: " << exception.what() << std::endl;  
    }
    plazza::Pizza pizza(plazza::Fantasia, plazza::M);

    for (auto ingredient : pizza.ingredients) {
        std::cout << ingredient << std::endl;
    }
    return 0;
}