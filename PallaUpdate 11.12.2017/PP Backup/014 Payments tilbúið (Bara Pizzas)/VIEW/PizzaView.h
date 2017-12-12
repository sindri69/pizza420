#ifndef PIZZAVIEW_H
#define PIZZAVIEW_H

#include<iostream>
#include<vector>
using namespace std;

class PizzaView
{
    public:
        PizzaView();

        void viewPizza(); /// Here we display name and prices for all types
        void viewPizzaTopping(string ptopping); /// Used for displaying each topping

        void viewPizza(string pizzaID); /// View all pizzas with matching pID

        void viewPizza_PayedFor(); /// Here we only show the pizzas that have been payed for
        void viewPizza_NotPayed(); /// Here we only show the pizzas that haven't been payed for
};

#endif // PIZZAVIEW_H
