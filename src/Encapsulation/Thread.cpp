/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** thread
*/

#include "Thread.hpp"

namespace plazza {

Thread::Thread(std::thread t) {
    thread.swap(t);
}

void Thread::Swap() {
    thread.swap(thread);
}

void Thread::Join() {
    thread.join();
}

void Thread::Detach() {
    thread.detach();
}

}