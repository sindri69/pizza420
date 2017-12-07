#ifndef MAINUI_H
#define MAINUI_H

#include "Basic.h"
#include "BasicMake.h"
#include "Pizza.h"
#include "PizzaMake.h"
#include "Type.h"
#include "TypeMake.h"
#include "Topping.h"
#include "ToppingMake.h"

class MainUI
{
    public:
        MainUI();

        void start_MainMenu();
        void start_AdminMenu();
        void start_AdminPizzaMenu();
        void start_AdminTypesMenu();
        void start_AdminToppingsMenu();
        void start_BakingMenu();
        void start_SalesMenu();

    private:
        Basic create_basic();
        BasicMake makebasic;

        Pizza create_pizza();
        PizzaMake makepizza;

        Type create_type();
        TypeMake maketype;

        Topping create_topping();
        ToppingMake maketopping;
};

#endif // MAINUI_H
