#ifndef DRINKUI_H
#define DRINKUI_H

#include "Drink.h"
#include "DrinkMake.h"

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
using namespace std;

class DrinkUI
{
    public:
        DrinkUI();
        void start_DrinksMenu();

    private:
        Drink create_drink();
        DrinkMake makedrink;
};

#endif // DRINKUI_H
