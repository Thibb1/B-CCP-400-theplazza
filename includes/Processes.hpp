/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Processes
*/

#ifndef PROCESSES_HPP_
#define PROCESSES_HPP_

#include "Plazza.hpp"

class Processes {
    public:
        pid_t _Pid;
        int status;

    public:
        Processes();
        virtual ~Processes() = default;
        const pid_t &GetPid();
        void WaitPid();
};

#endif /* !PROCESSES_HPP_ */
