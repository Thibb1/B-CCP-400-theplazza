/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

class Mutex {
    public:
        Mutex();
        virtual ~Mutex() = default;
        void Lock();
        void Unlock();
};

#endif /* !MUTEX_HPP_ */
