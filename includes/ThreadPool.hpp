/*
** EPITECH PROJECT, 2022
** TODO.hpp
** File description:
** TODO
*/

#pragma once

namespace plazza {
    class ThreadPool {
    private:
        std::vector<std::thread> mThreads{};
    public:
        ThreadPool() = default;

        ThreadPool(const ThreadPool &) = delete;

        ThreadPool(ThreadPool &&) = delete;

        ThreadPool &operator=(const ThreadPool &) = delete;

        ThreadPool &operator=(ThreadPool &&) = delete;

        ~ThreadPool() {
            release();
        };

        template<typename Function, typename ...Args>
        void add(Function &&fn, Args &&...args) {
            mThreads.emplace_back(std::forward<Function>(fn), std::forward<Args>(args)...);
        }

        void remove(size_t position) {
            mThreads[position].join();
            mThreads.erase(mThreads.begin() + long(position));
        }

        void release() {
            for (auto &thread: mThreads)
                thread.join();
            mThreads.clear();
        }
    };
}