/*
** EPITECH PROJECT, 2022
** Reception.cpp
** File description:
** TODO
*/

#include "Reception.hpp"

namespace plazza {

std::unordered_map<std::string, int> PizzaTypes {
    {"regina", 1},
    {"margarita", 2},
    {"americana", 4},
    {"fantasia", 8}
};

std::unordered_map<std::string, int> PizzaSizes {
    {"S", 1},
    {"M", 2},
    {"L", 4},
    {"XL", 8},
    {"XXL", 16}
};

void Reception::run()
{
    std::cout << "> ";
    std::string line;
    while (getline(std::cin, line)) {
        bool error = ParseCommand(line);
        if (RegUtils::isMatch(line, "QUIT", std::regex::icase)) {
            return;
        } else if (RegUtils::isMatch(line, "status", std::regex::icase)) {
            PrintKitchenStatus();
        } else if (error) {
        std::cout << "ERROR: Wrong pizza command" << std::endl;
        }
        std::cout << "> ";
    }
}

bool Reception::ParseCommand(const std::string& line) {
    std::string input = RegUtils::removeSpaces(line);
    stringV commands = RegUtils::split(input, "; ?");

    if (commands.empty())
        return true;

    for (auto &command : commands) {

        if (command.empty())
            return true;

        stringV orders = RegUtils::split(command, " ");

        if (orders.size() != 3)
            return true;

        if (!RegUtils::isMatch(orders[0], "Regina|Margarita|Americana|Fantasia", std::regex::icase)
            || !RegUtils::isMatch(orders[1], "S|M|L|XL|XXL")
            || !RegUtils::isMatch(orders[2], "x[1-9]\\d*"))
            return true;

        std::string number = RegUtils::getMatch(orders[2], "x([1-9]\\d*)")[1];

        StartReception(orders[0], orders[1], number);
    }
    return false;
}

void Reception::StartReception(std::string pizza, std::string size, const std::string &number)
{
    std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
    std::cout << "Order placed: " << pizza << ", " << size << ", " << number << std::endl;
    auto _type = static_cast<PizzaType>(PizzaTypes[pizza]);
    auto _size = static_cast<PizzaSize>(PizzaSizes[size]);
    Pizza a(_type, _size);

    SendPizzaToKitchen(a);
}

void Reception::SendPizzaToKitchen(Pizza pizza) {
    // get kitchen ID of an open kitchen
    auto id = GetFreeKitchen();
    // Send a message with pizza type and kitchen ID
    // R(order) -> K
    // K(bool) -> R (if no resp create a K?)
}

void Reception::PrintKitchenStatus() {
    std::cout << "Status" << std::endl;
    // Read each kitchen data via a message (maybe needs a lock)
    // R(info?) -> K
    // K(infos) -> R
    // Print infos
}

int Reception::GetFreeKitchen() {
    // Read each kitchen if free cook (maybe needs a lock)
    // Maybe get a message or smth
    // R(free cooks?) -> K
    // K(bool) -> R
    // If nothing found fork and return ID of that fork
    // auto id = GetNewKitchen();
    return 0;
}

int Reception::GetNewKitchen() {
    // Create a new kitchen after a fork and return its ID
    Kitchen newKitchen(++kitchens, CookingTime, Cooks, RefillTime);
    return kitchens;
}

}