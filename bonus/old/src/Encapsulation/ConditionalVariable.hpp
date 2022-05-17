/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** ConditionalVariable
*/

#pragma once

#include <condition_variable>
#include "Mutex.hpp"

namespace plazza {

class ConditionalVariable {
    public:
        Mutex _mutex;
        std::condition_variable conditionVariable;

    public:
        ConditionalVariable() = default;
        virtual ~ConditionalVariable() = default;
        void NotifyOne();
        void NotifyAll();
        void Wait();
};

}
