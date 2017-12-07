#ifndef TOPPING_H
#define TOPPING_H

#include <string>
#include <iostream>
using namespace std;

class Topping
{
    public:
        Topping(string name, double price);

        string get_name() const;
        double get_price() const;

        friend ostream& operator << (ostream& out, const Topping& topping);

    private:
        string name;
        double price;
};

#endif // TOPPING_H
