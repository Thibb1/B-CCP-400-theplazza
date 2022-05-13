/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

namespace plazza {
    Kitchen::Kitchen(int id, double CookingTime, long Cooks, long RefillTime)
    : id(id), CookingTime(CookingTime), Cooks(Cooks), RefillTime(RefillTime) {
        process = new Process();
        mutex = new Mutex;
        if (process->GetPid() == 0) {
            Start();
        }
        process->WaitPid();
    }

    void Kitchen::Start() {
        ThreadPool pool;
    }
}
