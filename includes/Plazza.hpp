/*
** EPITECH PROJECT, 2022
** Plazza.hpp
** File description:
** TODO
*/

#pragma once

#include <regex>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <csignal>
#include <sys/types.h>
#include <unistd.h>

#include "PlazzaError.hpp"
#include "RegexUtils.hpp"
#include "Pizza.hpp"

#define MATCH "([[:alpha:]]+ (?:XXL|XL|X|M|S) x[1-9]\\d*)"
#define EXIT_ERROR 84
