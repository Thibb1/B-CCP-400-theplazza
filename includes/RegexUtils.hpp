/*
** EPITECH PROJECT, 2022
** RegexUtils.hpp
** File description:
** regex utils
*/

#pragma once

#include <regex>

#include "Plazza.hpp"

typedef std::vector<std::string> stringV;

class RegUtils {
public:
    RegUtils() = default;
    ~RegUtils() = default;
    static bool isMatch(std::string const &s, std::string const &r);
    static stringV getMatch(std::string const &s, std::string const &r);
    static std::string removeSpaces(std::string const &str);
};
