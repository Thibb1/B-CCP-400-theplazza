/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** ConditionnalVariable
*/

#include "ConditionnalVariable.hpp"

namespace plazza {

ConditionnalVariable::ConditionnalVariable() {
    
}

void ConditionnalVariable::NotifyOne() {
    conditionVariable.notify_one();
}

void ConditionnalVariable::NotifyAll() {
    conditionVariable.notify_all();
}

void ConditionnalVariable::Wait() {
    _mutex.Lock();
    conditionVariable.wait(_mutex.mutex);
}

}