/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Process
*/

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <csignal>
#include <unistd.h>
#include <sys/wait.h>
#include "PlazzaError.hpp"

class Process {
    private:
        pid_t pid;
        int status;

    public:
        Process();
        pid_t getPid();
        void waitPid();
};

#endif /* !PROCESS_HPP_ */
