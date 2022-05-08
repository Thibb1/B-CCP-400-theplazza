/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** thread
*/

#include "Thread.hpp"

namespace plazza {

Thread::Thread(std::thread t) {
    this->thread.swap(t);
}

void Thread::Swap() {
    this->thread.swap(thread);
}

void Thread::Join() {
    this->thread.join();
}

void Thread::Detach() {
    this->thread.detach();
}

}