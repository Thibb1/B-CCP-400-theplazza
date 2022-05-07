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
            std::unique_lock<std::mutex> lock(this->mutex);
            this->queue.push(value);
        }

        bool tryPop(Type &value) {
            std::unique_lock<std::mutex> lock(this->mutex);

            if (this->queue.empty()) {
                return false;
            } else {
                value = this->queue.front();
                this->queue.pop();
                return true;
            }
        }

        size_t size() {
            std::unique_lock<std::mutex> lock(this->mutex);
            return this->queue.size();
        }
};