#ifndef PIZZAUI_H
#define PIZZAUI_H

#include "Basic.h"
#include "BasicMake.h"
#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !

class PizzaUI
{
    public:
        PizzaUI();

        void start_PizzaMenu();

    private:
        Basic create_basic();
        BasicMake makebasic;
};

#endif // PIZZAUI_H
