/*
** EPITECH PROJECT, 2022
** PlazzaError.hpp
** File description:
** error classes
*/

#pragma once

#include <string>
#include <exception>

typedef std::string Error;
class PlazzaError : public std::exception {
private:
    const Error ErrorMessage;
public:
    explicit PlazzaError(Error Message = "An error occurred") :
        ErrorMessage("./plazza: " + std::move(Message)) {}
    [[nodiscard]] const char *what() const noexcept override {
        return ErrorMessage.c_str();
    }
};

class PlazzaUsageError : public PlazzaError {
public:
    explicit PlazzaUsageError(Error Message = "\nUSAGE: ./plazza <cooking_time> <cooks> <refill_time>") :
        PlazzaError(std::move(Message)) {}
};

class PlazzaRuntimeError : public PlazzaError {
public:
    explicit PlazzaRuntimeError(Error Message = "A runtime error occurred") :
        PlazzaError(std::move(Message)) {}
};

