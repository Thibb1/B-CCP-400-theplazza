/*
** EPITECH PROJECT, 2022
** Plazza.hpp
** File description:
** TODO
*/

#pragma once

#include <string>
#include <regex>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "PlazzaError.hpp"
#include "RegexUtils.hpp"

#define MATCH "(?: *([[:alpha:]]+) (S|M|L|XL|XXL) x(\\d+))"
#define EXIT_ERROR 84