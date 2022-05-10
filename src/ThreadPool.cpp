/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool() : concurrency(std::thread::hardware_concurrency()), threads(concurrency), running(true) {
    createWorkers();
}

ThreadPool::~ThreadPool()
{
    running = false;
    _conditionVariable.notify_all();

    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}
