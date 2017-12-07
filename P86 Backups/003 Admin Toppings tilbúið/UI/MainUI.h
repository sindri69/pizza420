#ifndef MAINUI_H
#define MAINUI_H

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
        void start_AdminTypesMenu();
        void start_AdminToppingsMenu();
        void start_BakingMenu();
        void start_SalesMenu();

    private:
        Type create_type();
        TypeMake maketype;
        Topping create_topping();
        ToppingMake maketopping;
};

#endif // MAINUI_H
