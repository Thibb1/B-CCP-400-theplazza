/*
** EPITECH PROJECT, 2022
** plazza.hpp
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <iostream>
#include <thread>

namespace plazza {

class Plazza {
    private:
        /* data */
    public:
        Plazza(/* args */);
        ~Plazza();
        parser();

        std::string _type;
        std::string _size;
        int number;
};
}

#endif /* !PLAZZA_HPP_ */
