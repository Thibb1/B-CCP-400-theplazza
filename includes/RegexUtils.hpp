/*
** EPITECH PROJECT, 2022
** RegexUtils.hpp
** File description:
** regex utils
*/


#pragma once

class RegUtils {
public:
    RegUtils() = default;
    ~RegUtils() = default;
    static bool isMatch(std::string const &str, std::string const &pattern);
    static std::smatch getMatch(std::string const &str, std::string const &pattern);
    static std::string removeSpaces(std::string const &str);
};
