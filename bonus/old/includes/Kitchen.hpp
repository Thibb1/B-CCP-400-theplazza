/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** Kitchen
*/

#pragma once

#include <vector>

#include "Process.hpp"
#include "Mutex.hpp"
#include "Thread.hpp"
#include "ThreadPool.hpp"

namespace plazza {
    class Kitchen {
    public:
        Kitchen(double CookingTime, long Cooks, long RefillTime);
        virtual ~Kitchen() = default;
        void Start();

    private:
        Process *process;
        Mutex *mutex;
        double CookingTime;
        long Cooks;
        long RefillTime;
    };
}
