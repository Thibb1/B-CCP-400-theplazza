/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include <atomic>
#include <vector>
#include <functional>
#include "SafeQueue.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"
#include "ConditionalVariable.hpp"

namespace plazza {

class ThreadPool {
    public:
        size_t concurrency;
        std::vector<std::thread> threads;
        std::atomic_bool running;
        Thread _thread;
        Mutex _mutex;
        SafeQueue<std::function<void()>> tasks;
        ConditionalVariable _conditionalVariable;

    public:
        ThreadPool();
        ~ThreadPool();
        void CreateWorkers();
        void WorkerRoutine();

        template<class Function, class... Args>
        void run(Function&& f, Args&&... args);
};

}

#endif /* !THREADPOOL_HPP_ */
