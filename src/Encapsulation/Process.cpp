/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Process
*/

#include "Process.hpp"

namespace plazza {

Process::Process() : pid(fork()) {
    if (this->pid < 0)
        throw PlazzaRuntimeError();
}

pid_t Process::GetPid() {
    return this->pid;
}

void Process::WaitPid() {
    waitpid(this->pid, &status, WNOHANG);
}

}