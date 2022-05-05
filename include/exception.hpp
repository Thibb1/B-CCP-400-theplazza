/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#pragma once

#include <exception>
#include <string>

namespace plazza {

class Exception : public std::exception {
    private:
        std::string message;
    public:
        Exception(const std::string &message) : message(message) {}
        const char *what() const noexcept override { return this->message.c_str(); }
};
}

#endif /* !EXCEPTION_HPP_ */
