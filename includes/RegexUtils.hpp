/*
** EPITECH PROJECT, 2022
** RegexUtils.hpp
** File description:
** regex utils
*/

#pragma once

#include <regex>

class RegUtils {
public:
    RegUtils() = default;
    ~RegUtils() = default;
    static bool isMatch(std::string const &s, std::string const &r);
    static boost::smatch getMatch(std::string const &s, std::string const &r);
    static std::string removeSpaces(std::string const &str);
};
