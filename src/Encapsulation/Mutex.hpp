/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** mutex
*/

#pragma once

#include <thread>
#include <mutex>

namespace plazza {

class Mutex {
    public:
        std::mutex mutex;

    public:
        Mutex();
        void Lock();
        void Unlock();
};

}