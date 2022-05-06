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
typedef std::regex::flag_type flag_type;

class RegUtils {
public:
    RegUtils() = default;
    ~RegUtils() = default;
    static bool isMatch(std::string const &s, std::string const &r, flag_type flag = std::regex::ECMAScript);
    static std::smatch getMatch(std::string const &s, std::string const &r);
    static stringV split(std::string const &s, std::string const &r);
    static std::string removeSpaces(std::string const &str);
};
