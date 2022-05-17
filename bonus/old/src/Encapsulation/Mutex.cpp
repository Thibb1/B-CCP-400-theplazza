/*
** EPITECH PROJECT, 2022
** B-CPP-400-LIL-4-1-theplazza
** File description:
** Mutex
*/

#include "Mutex.hpp"

namespace plazza {

void Mutex::Lock() {
    mutex.lock();
}

void Mutex::Unlock() {
    mutex.unlock();
}

}