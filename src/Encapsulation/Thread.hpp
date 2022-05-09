/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** thread
*/

#pragma once

#include <thread>

namespace plazza {

class Thread {
    public:
        std::thread thread;
    
    public:
        Thread(std::thread t);
        virtual ~Thread() = default;
        void Swap();
        void Join();
        void Detach();
        bool Joinable();
};

}