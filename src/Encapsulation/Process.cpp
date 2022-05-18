/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Process
*/

#include "Process.hpp"

namespace plazza {

Process::Process() : pid(fork()) {
    if (pid < 0)
        throw PlazzaUsageError();
}

pid_t Process::GetPid() const {
    return pid;
}

void Process::WaitPid() {
    waitpid(pid, &status, WNOHANG);
}

}