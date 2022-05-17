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
        std::unique_lock<std::mutex> mutex;

    public:
        Mutex() = default;
        virtual ~Mutex() = default;
        void Lock();
        void Unlock();
};

}