/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Process
*/

#include "Process.hpp"

Process::Process() : pid(fork()) {
    if (this->pid < 0)
        throw PlazzaRuntimeError();
}

pid_t Process::getPid() {
    return this->pid;
}

void Process::waitPid() {
    waitpid(this->pid, &status, WNOHANG);
}