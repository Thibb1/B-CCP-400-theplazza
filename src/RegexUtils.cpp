/*
** EPITECH PROJECT, 2022
** RegexUtils.cpp
** File description:
** tools to check patterns
*/

#include "Plazza.hpp"

bool RegUtils::isMatch(std::string const &str, std::string const &pattern)
{
    boost::regex reg(pattern);
    return boost::regex_match(str, reg);
}

boost::smatch RegUtils::getMatch(std::string const &str, std::string const &pattern)
{
    boost::regex reg(pattern);
    boost::smatch match;
    boost::regex_search(str, match, reg);
    return match;
}

std::string RegUtils::removeSpaces(std::string const &str)
{
    boost::regex reg("(\\s)\\s*");
    return boost::regex_replace(str, reg, " ");
}
//([a-zA-Z]+(S|M|L|XL|XXL)x\d+;{0,1})+
//(([[:alpha:]]+)(?:XXL|XL|X|M|S)x\d+(?:;|\n))