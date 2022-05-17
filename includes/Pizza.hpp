/*
** EPITECH PROJECT, 2022
** Pizza.hpp
** File description:
** Pizza Classes and enums
*/

#pragma once

#include <vector>
#include <map>
#include <string_view>

namespace plazza {
    enum PizzaType {
        Regina = 1, Margarita = 2, Americana = 4, Fantasia = 8
    };

    enum PizzaIngredient {
        Doe = 0,
        Tomato = 1,
        Gruyere = 2,
        Ham = 3,
        Mushrooms = 4,
        Steak = 5,
        Eggplant = 6,
        GoatCheese = 7,
        ChiefLove = 8,
    };

    enum PizzaSize {
        S = 1, M = 2, L = 4, XL = 8, XXL = 16
    };

    class IPizza {
    protected:
        int mCookingTime{};
        PizzaSize mSize{};
        PizzaType mType{};
        std::vector<PizzaIngredient> mIngredients{};
    public:
        virtual ~IPizza() = default;

        const PizzaType &getType() { return mType; };

        const PizzaSize &getSize() { return mSize; };

        [[nodiscard]] const int &getCookingTime() const { return mCookingTime; };

        const std::vector<PizzaIngredient> &getIngredients() { return mIngredients; };
    };

    class regina : public IPizza {
    public:
        explicit regina(const PizzaSize &size) {
            mCookingTime = 2;
            mSize = size;
            mType = PizzaType::Regina;
            mIngredients.push_back(PizzaIngredient::Doe);
            mIngredients.push_back(PizzaIngredient::Tomato);
            mIngredients.push_back(PizzaIngredient::Gruyere);
            mIngredients.push_back(PizzaIngredient::Ham);
            mIngredients.push_back(PizzaIngredient::Mushrooms);
        };

        ~regina() override = default;
    };

    class margarita : public IPizza {
    public:
        explicit margarita(const PizzaSize &size) {
            mCookingTime = 1;
            mSize = size;
            mType = PizzaType::Margarita;
            mIngredients.push_back(PizzaIngredient::Doe);
            mIngredients.push_back(PizzaIngredient::Tomato);
            mIngredients.push_back(PizzaIngredient::Gruyere);
        };

        ~margarita() override = default;
    };

    class americana : public IPizza {
    public:
        explicit americana(const PizzaSize &size) {
            mCookingTime = 2;
            mSize = size;
            mType = PizzaType::Americana;
            mIngredients.push_back(PizzaIngredient::Doe);
            mIngredients.push_back(PizzaIngredient::Tomato);
            mIngredients.push_back(PizzaIngredient::Gruyere);
            mIngredients.push_back(PizzaIngredient::Steak);
        };

        ~americana() override = default;
    };

    class fantasia : public IPizza {
    public:
        explicit fantasia(const PizzaSize &size) {
            mCookingTime = 4;
            mSize = size;
            mType = PizzaType::Fantasia;
            mIngredients.push_back(PizzaIngredient::Doe);
            mIngredients.push_back(PizzaIngredient::Tomato);
            mIngredients.push_back(PizzaIngredient::Eggplant);
            mIngredients.push_back(PizzaIngredient::GoatCheese);
            mIngredients.push_back(PizzaIngredient::ChiefLove);
        };

        ~fantasia() override = default;
    };

    inline std::map<int, std::string_view> mapPizzaIngredients{{0, "Doe"},
                                                               {1, "Tomato"},
                                                               {2, "Gruyere"},
                                                               {3, "Ham"},
                                                               {4, "Mushrooms"},
                                                               {5, "Steak"},
                                                               {6, "Eggplant"},
                                                               {7, "GoatCheese"},
                                                               {8, "ChiefLove"},};

    inline std::map<std::string_view, PizzaType> mapPizzaType{{"regina",    Regina},
                                                              {"margarita", Margarita},
                                                              {"americana", Americana},
                                                              {"fantasia",  Fantasia},};

    inline std::map<PizzaType, std::string_view> revMapPizzaType{{Regina,    "regina"},
                                                                 {Margarita, "margarita"},
                                                                 {Americana, "americana"},
                                                                 {Fantasia,  "fantasia"},};

    inline std::map<std::string_view, PizzaSize> mapPizzaSize{{"S",   S},
                                                              {"M",   M},
                                                              {"L",   L},
                                                              {"XL",  XL},
                                                              {"XXL", XXL},};

    inline std::map<PizzaSize, std::string_view> revMapPizzaSize{{S,   "S"},
                                                                 {M,   "M"},
                                                                 {L,   "L"},
                                                                 {XL,  "XL"},
                                                                 {XXL, "XXL"},};
}