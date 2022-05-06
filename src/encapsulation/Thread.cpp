/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** thread
*/

#include "Thread.hpp"

Thread::Thread(std::thread thread)
{
    Swap(thread);
}

void Thread::Swap(std::thread thread)
{
    _Thread.swap(thread);
}

void Thread::Join()
{
    _Thread.join();
}

void Thread::Detach()
{
    _Thread.detach();
}