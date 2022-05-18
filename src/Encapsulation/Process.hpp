/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Process
*/

#pragma once

#include <unistd.h>
#include "Exceptions.hpp"
#include <sys/wait.h>

namespace plazza {

class Process {
    public:
        pid_t pid;
        int status{};

    public:
        Process();
        virtual ~Process() = default;
        pid_t GetPid() const;
        void WaitPid();
};

}