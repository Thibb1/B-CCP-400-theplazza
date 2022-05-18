#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <condition_variable>
#include <functional>
#include <atomic>
#include "safeQueue.hpp"

class ThreadPool {
    private:
        size_t concurrency;
        std::vector<std::thread> threads;
        std::atomic_bool running;
        std::mutex mutex;
        SafeQueue<std::function<void()>> tasks;
        std::condition_variable condition_variable;
        
        void createWorkers();
        void workerRoutine();
    public:
        ThreadPool();
        ~ThreadPool();

        template<class Function, class... Args>
        void run(Function&& f, Args&&... args);
};

ThreadPool::ThreadPool() : concurrency(std::thread::hardware_concurrency()), threads(concurrency), running(true) {
    createWorkers();
}

ThreadPool::~ThreadPool() {
    this->running = false;
    this->condition_variable.notify_all();

    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void ThreadPool::workerRoutine() {
    std::function<void()> task;

    while (this->running) {
        if (this->tasks.tryPop(task)) {
            task();
        } else {
            std::unique_lock<std::mutex> lock(this->mutex);
            if (this->running) {
                this->condition_variable.wait(lock);
            }  
        }
    }
}

void ThreadPool::createWorkers() {
    for (size_t i = 0; i < this->concurrency; ++i) {
        this->threads.emplace_back(&ThreadPool::workerRoutine, this);
    }
}

template<class Function, class... Args>
void ThreadPool::run(Function &&function, Args&&... args) {
    this->tasks.push(std::bind(std::forward<Function>(function), std::forward<Args>(args)...));
    this->condition_variable.notify_one();
}

int main() {
    ThreadPool pool;

    pool.run([] (const std::string &message) { std::cout << message << std::endl; }, "hello !");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}