/*
** EPITECH PROJECT, 2022
** RegexUtils.cpp
** File description:
** tools to check patterns
*/

#include "Plazza.hpp"

bool RegUtils::isMatch(std::string const &str, std::string const &pattern)
{
    std::regex reg(pattern);
    return std::regex_match(str, reg);
}

std::smatch RegUtils::getMatch(std::string const &str, std::string const &pattern)
{
    std::regex reg(pattern);
    std::smatch match;
    std::regex_search(str, match, reg);
    return match;
}

std::string RegUtils::removeSpaces(std::string const &str)
{
    std::regex reg("(\\s)\\s*");
    return std::regex_replace(str, reg, " ");
}
//([a-zA-Z]+(S|M|L|XL|XXL)x\d+;{0,1})+
//(([[:alpha:]]+)(?:XXL|XL|X|M|S)x\d+(?:;|\n))