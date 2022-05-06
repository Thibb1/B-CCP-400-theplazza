/*
** EPITECH PROJECT, 2022
** RegexUtils.cpp
** File description:
** tools to check patterns
*/

#include "RegexUtils.hpp"

bool RegUtils::isMatch(std::string const &str, std::string const &pattern, flag_type flag)
{
    std::regex reg(pattern, flag);
    return std::regex_match(str, reg);
}

std::smatch RegUtils::getMatch(std::string const &str, std::string const &pattern)
{
    std::smatch match;
    std::regex reg(pattern);
    std::regex_match(str, match, reg);
    return match;
}

stringV RegUtils::split(std::string const &str, std::string const &pattern)
{
    std::regex reg(pattern);
    std::sregex_token_iterator iterator(str.begin(), str.end(), reg, -1);
    std::sregex_token_iterator end;
    return {iterator, end};
}

std::string RegUtils::removeSpaces(std::string const &str)
{
    std::regex reg("\\s{1,}");
    return std::regex_replace(str, reg, " ");
}
