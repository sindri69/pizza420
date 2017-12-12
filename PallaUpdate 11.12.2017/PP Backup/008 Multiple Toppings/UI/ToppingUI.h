#ifndef TOPPINGUI_H
#define TOPPINGUI_H

#include "Topping.h"
#include "ToppingMake.h"

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
using namespace std;

class ToppingUI
{
    public:
        ToppingUI();
        void start_ToppingsMenu();

    private:
        Topping create_topping();
        ToppingMake maketopping;
};

#endif // TOPPINGUI_H
