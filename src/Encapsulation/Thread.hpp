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
        Thread();
        void Swap();
        void Join();
        void Detach();
};

}