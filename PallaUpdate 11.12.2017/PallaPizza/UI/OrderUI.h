#ifndef ORDERUI_H
#define ORDERUI_H

#include "Pizza.h"
#include "PizzaMake.h"

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
using namespace std;

class OrderUI
{
    public:
        OrderUI();

        void start_OrdersMenu();

    private:
        Pizza create_pizza(string pID);
        PizzaMake makepizza;
};

#endif // ORDERUI_H
