/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** Pizza
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>

namespace plazza {

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum class Ingredient
{
    Dough,
    Tomato,
    Gruyere,
    Ham,
    Mushrooms,
    Steak,
    Eggplant,
    GoatCheese,
    ChiefLove
};

std::ostream &operator<<(std::ostream &stream, PizzaSize size);
std::ostream &operator<<(std::ostream &stream, PizzaType type);
std::ostream &operator<<(std::ostream &stream, Ingredient ingredient);

class IngredientList {
    public:
        using ingredient_list = std::vector<Ingredient>;
    private:
        std::array<ingredient_list, 4> ingredientsByPizzaType;

        void initMargaritaIngredients();
        void initReginaIngredients();
        void initAmericanaIngredients();
        void initFantasiaIngredients();
        static uint32_t pizzaTypeId(PizzaType type);
    public:
        IngredientList();
        const ingredient_list &operator[](PizzaType type) const;
};

class Pizza {
    public:
        Pizza(PizzaType type, PizzaSize size);

    private:
        PizzaType type;
        PizzaSize size;
        inline static const IngredientList ingredientList;

    public:
        const IngredientList::ingredient_list &ingredients;
};

}