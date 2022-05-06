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

/* int main() {
    SafeQueue<int> queue;
    std::vector<std::thread> threads(T);

    for (size_t i = 0; i < T; ++i) {
        threads.push_back(std::thread([&queue] () {
            for (size_t i = 0; i < T; ++i) {
                queue.push(i);
            }
        }));
    }

    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    std::cout << queue.size() << std::endl;
    threads.clear();

    for (size_t i = 0; i < T; i++) {
        threads.push_back(std::thread([&queue] () {
            int value;
            for (size_t i = 0; i < T; i++) {
                queue.tryPop(value);
            }
        }));
    }

    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    std::cout << queue.size() << std::endl;
} */