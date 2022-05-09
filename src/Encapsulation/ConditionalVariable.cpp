/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** ConditionalVariable
*/

#include "ConditionalVariable.hpp"

namespace plazza {

void ConditionalVariable::NotifyOne() {
    conditionVariable.notify_one();
}

void ConditionalVariable::NotifyAll() {
    conditionVariable.notify_all();
}

void ConditionalVariable::Wait() {
    _mutex.Lock();
    conditionVariable.wait(_mutex.mutex);
}

}