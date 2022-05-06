/*
** EPITECH PROJECT, 2022
** RegexUtils.cpp
** File description:
** tools to check patterns
*/

#include "RegexUtils.hpp"

bool RegUtils::isMatch(std::string const &str, std::string const &pattern)
{
    std::regex reg(pattern);
    return std::regex_match(str, reg);
}

stringV RegUtils::getMatch(std::string const &str, std::string const &pattern)
{
    stringV res;
    std::string::const_iterator text_iter = str.cbegin();
    std::smatch match;
    std::regex reg(pattern, std::regex::extended);
    while (std::regex_match(text_iter, str.end(), match, reg)) {
        res.push_back(match[0]);
    }
    // std::regex_search(str, match, reg);
    return res;
}


//compiledRegex = std::regex(regex, std::tr1::regex_constants::extended);
//
//while (regex_search(text_iter, text.end(), results, compiledRegex))
//{
//int count = results.size();
//// Alloc pointer array based on count * sizeof(mystruct).
//for ( std::cmatch::iterator group = results.begin();
//group != results.end();
//++group )
//{
//// If you uses grouping in your search here you can access each group
//}
//
//std::cout << std::string(results[0].first, results[0].second) << endl;
//text_iter = results[0].second;
//}

std::string RegUtils::removeSpaces(std::string const &str)
{
    std::regex reg("(\\s)\\s*");
    return std::regex_replace(str, reg, " ");
}
//([a-zA-Z]+(S|M|L|XL|XXL)x\d+;{0,1})+
//(([[:alpha:]]+)(?:XXL|XL|X|M|S)x\d+(?:;|\n))