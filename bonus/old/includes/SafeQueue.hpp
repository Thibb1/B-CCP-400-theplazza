/*
** EPITECH PROJECT, 2022
** SafeQueue
** File description:
** Queue
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>

constexpr int N = 1;
constexpr size_t T = 100;

template <typename Type>
class SafeQueue {
    private:
        std::queue<Type> queue;
        std::mutex mutex;
    public:
        void push(const Type &value) {
            std::unique_lock<std::mutex> lock(mutex);
            queue.push(value);
        }

        bool tryPop(Type &value) {
            std::unique_lock<std::mutex> lock(mutex);

            if (queue.empty()) {
                return false;
            } else {
                value = queue.front();
                queue.pop();
                return true;
            }
        }

        size_t size() {
            std::unique_lock<std::mutex> lock(mutex);
            return queue.size();
        }
};