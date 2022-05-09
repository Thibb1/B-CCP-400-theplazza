/*
** EPITECH PROJECT, 2022
** B-CCP-400-LIL-4-1-theplazza-marine.poteau
** File description:
** Pizza
*/

#include "Pizza.hpp"

namespace plazza {

std::ostream &operator<<(std::ostream &stream, PizzaSize size) {
    switch (size) {
        PRINT_ENUM(S)
        PRINT_ENUM(M)
        PRINT_ENUM(L)
        PRINT_ENUM(XL)
        PRINT_ENUM(XXL)
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, PizzaType type) {
    switch (type) {
        PRINT_ENUM(Margarita)
        PRINT_ENUM(Regina)
        PRINT_ENUM(Americana)
        PRINT_ENUM(Fantasia)
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Ingredient ingredient) {
    switch (ingredient) {
        PRINT_ENUM(Ingredient::Doe)
        PRINT_ENUM(Ingredient::Tomato)
        PRINT_ENUM(Ingredient::Gruyere)
        PRINT_ENUM(Ingredient::Ham)
        PRINT_ENUM(Ingredient::Mushrooms)
        PRINT_ENUM(Ingredient::Steak)
        PRINT_ENUM(Ingredient::Eggplant)
        PRINT_ENUM(Ingredient::GoatCheese)
        PRINT_ENUM(Ingredient::ChiefLove)
    }
    return stream;
}

IngredientList::IngredientList() {
    initMargaritaIngredients();
    initReginaIngredients();
    initAmericanaIngredients();
    initFantasiaIngredients();
}

void IngredientList::initMargaritaIngredients() {
    ingredient_list &ingredients = ingredientsByPizzaType[PizzaType::Margarita];

    ingredients.reserve(3);
    ingredients.push_back(Ingredient::Doe);
    ingredients.push_back(Ingredient::Tomato);
    ingredients.push_back(Ingredient::Gruyere);
}

void IngredientList::initReginaIngredients() {
    ingredient_list &ingredients = ingredientsByPizzaType[PizzaType::Regina];

    ingredients.reserve(5);
    ingredients.push_back(Ingredient::Doe);
    ingredients.push_back(Ingredient::Tomato);
    ingredients.push_back(Ingredient::Gruyere);
    ingredients.push_back(Ingredient::Ham);
    ingredients.push_back(Ingredient::Mushrooms);
}

void IngredientList::initAmericanaIngredients() {
    ingredient_list &ingredients = ingredientsByPizzaType[PizzaType::Americana];

    ingredients.reserve(4);
    ingredients.push_back(Ingredient::Doe);
    ingredients.push_back(Ingredient::Tomato);
    ingredients.push_back(Ingredient::Gruyere);
    ingredients.push_back(Ingredient::Steak);
}

void IngredientList::initFantasiaIngredients() {
    ingredient_list &ingredients = ingredientsByPizzaType[PizzaType::Fantasia];

    ingredients.reserve(5);
    ingredients.push_back(Ingredient::Doe);
    ingredients.push_back(Ingredient::Tomato);
    ingredients.push_back(Ingredient::Eggplant);
    ingredients.push_back(Ingredient::GoatCheese);
    ingredients.push_back(Ingredient::ChiefLove);
}

const IngredientList::ingredient_list &IngredientList::operator[](PizzaType type) const {
    return ingredientsByPizzaType[type];
}

Pizza::Pizza(PizzaType type, PizzaSize size) : type(type), size(size), ingredients(ingredientList[type]) {}

}
