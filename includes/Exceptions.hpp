/*
** EPITECH PROJECT, 2022
** Exceptions.hpp
** File description:
** Exceptions for plazza
*/

#pragma once

#include <exception>
#include <string>
#include <utility>

#define EXIT_ERROR 84

namespace plazza {
    class PlazzaError : public std::exception {
    protected:
        const std::string mError;
    public:
        explicit PlazzaError(std::string error) : mError(std::move(error)) {};

        [[nodiscard]] const char *what() const noexcept override { return mError.c_str(); };
    };

    class PlazzaBadCommand : public PlazzaError {
    public:
        PlazzaBadCommand() : PlazzaError("./plazza : bad command") {};
    };

    class PlazzaUsageError : public PlazzaError {
    public:
        PlazzaUsageError() : PlazzaError("\nUSAGE: ./plazza <cooking_time> <cooks> <refill_time>") {};
    };
}