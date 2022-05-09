/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** ConditionnalVariable
*/

#pragma once

#include <condition_variable>
#include "Mutex.hpp"

namespace plazza {

class ConditionnalVariable {
    public:
        Mutex _mutex;
        std::condition_variable conditionVariable;

    public:
        ConditionnalVariable();
        virtual ~ConditionnalVariable() = default;
        void NotifyOne();
        void NotifyAll();
        void Wait();
};

}
