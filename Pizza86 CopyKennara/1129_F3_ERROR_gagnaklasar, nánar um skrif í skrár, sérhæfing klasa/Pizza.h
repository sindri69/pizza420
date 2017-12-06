#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include "topping.h"
using namespace std;

class Pizza
{
    public:
        Pizza();
        Pizza(int numberOfToppings);
        virtual ~Pizza();

        void initialize(int numberOfToppings);
        void clean();

        void addTopping(Topping topping);

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (const ostream& out, Pizza& pizza);

    protected:

    private:
        Topping *toppings;
        int toppingCount;

        int currentToppingNum;
};

#endif // PIZZA_H
