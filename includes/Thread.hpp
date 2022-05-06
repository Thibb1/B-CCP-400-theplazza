/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <Plazza.hpp>

class Thread {
    public:
        std::thread _Thread;
    
    public:
        Thread(std::thread thread);
        virtual ~Thread() = default;
        void Swap();
        void Join();
        void Detach();
};

#endif /* !THREAD_HPP_ */
