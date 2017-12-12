#ifndef BASIC_H
#define BASIC_H

#include <iostream>
using namespace std;

class Basic
{
    public:
        Basic(double priceL, double priceM, double priceS); /// Basic Constructor

        double get_priceL() const;
        double get_priceM() const;
        double get_priceS() const;

        friend ostream& operator << (ostream& out, const Basic& basic);

    private: /// Basic only stores the values for the price of ( Large / Medium / Small ) Basic Pizzas
        double priceL;
        double priceM;
        double priceS;
};

#endif // BASIC_H
