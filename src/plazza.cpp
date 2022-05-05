/*
** EPITECH PROJECT, 2022
** plazza.cpp
** File description:
** plazza
*/

#include "plazza.hpp"

plazza::plazza(/* args */)
{
    std::thread first ();
    std::thread second ();

    while (1)
    {
        std::cin >> plazza::type;
        if ("regina" == type)
            std::cout << "ok" << std::endl;
        else if ("americana" == s)
            std::cout << "ok" << std::endl;
        else {
            std::cerr << "Error: not a pizza." << std::endl;
            return (84);
        }
    }
    return (0); 
}

plazza::~plazza()
{
}
