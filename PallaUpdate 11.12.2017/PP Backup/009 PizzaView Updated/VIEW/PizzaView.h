#ifndef PIZZAVIEW_H
#define PIZZAVIEW_H

#include<iostream>
#include<vector>
using namespace std;

class PizzaView
{
    public:
        PizzaView();

        void viewPizza();        /// Here we display name and prices for all types
        void viewPizzaTopping(string ptopping); /// Used for displaying each topping
};

#endif // PIZZAVIEW_H
