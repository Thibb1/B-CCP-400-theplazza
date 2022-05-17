/*
** EPITECH PROJECT, 2022
** Logger.hpp
** File description:
** logs to console and log.tx
*/

#pragma once

#include <mutex>
#include <iostream>
#include <fstream>

namespace plazza {
    inline void printOnFile() {}

    inline void printOut() {}

    template<typename T, typename... Args>
    void printOnFile(T t, Args ...next) {
        std::ofstream file("log.txt", std::ios::app);
        file << t;
        file.close();
        printOnFile(next...);
    }

    template<typename T, typename... Args>
    void printOut(T t, Args ...next) {
        std::cout << t;
        printOut(next...);
    }

    template<typename T, typename ...Args>
    void log(T t, Args ...args) {
        static std::mutex mutex;
        mutex.lock();
        printOnFile(t, args...);
        printOut(t, args...);
        mutex.unlock();
    }
}