/*
** EPITECH PROJECT, 2022
** RegexUtils.hpp
** File description:
** regex utils
*/

#pragma once

#include <regex>

typedef std::vector<std::string> vString;
typedef std::regex::flag_type flag_type;

class RegUtils {
public:
    RegUtils() = default;

    ~RegUtils() = default;

    static bool isMatch(std::string const &s, std::string const &r, flag_type flag = std::regex::ECMAScript);

    static std::smatch getMatch(std::string const &s, std::string const &r);

    static vString split(std::string const &s, std::string const &r);

    static std::string removeSpaces(std::string const &str);
};
