#ifndef TOPPING_H
#define TOPPING_H

#include <string>
#include <iostream>
using namespace std;

class Topping
{
    public:
        Topping(string name, double priceL, double priceM, double priceS);

        string get_name() const;
        double get_priceL() const;
        double get_priceM() const;
        double get_priceS() const;

        friend ostream& operator << (ostream& out, const Topping& topping);

    private:
        string name;
        double priceL;
        double priceM;
        double priceS;
};

#endif // TOPPING_H
