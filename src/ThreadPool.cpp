/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool() : concurrency(std::thread::hardware_concurrency()), threads(concurrency), running(true) {
    CreateWorkers();
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

void ThreadPool::WorkerRoutine() {
    std::function<void()> task;

    while (running) {
        if (tasks.tryPop(task)) {
            task();
        } else {
            std::unique_lock<std::mutex> lock(this->mutex);
            if (running) {
                this->condition_variable.wait(lock);
            }  
        }
    }
}

void ThreadPool::CreateWorkers() {
    std::function<void()> task;

    
     
}