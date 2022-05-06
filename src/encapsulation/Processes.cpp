/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Processes
*/

#include "Processes.hpp"

Processes::Processes() : _Pid(fork())
{
    if (_Pid < 0)
        throw PlazzaRuntimeError();
}

const pid_t &Processes::GetPid()
{
    return (_Pid);
}

void Processes::WaitPid()
{
    waitpid(_Pid, &status, WNOHANG);
}