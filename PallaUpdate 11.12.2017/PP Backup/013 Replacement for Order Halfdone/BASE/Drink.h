#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <iostream>
using namespace std;

class Drink
{
    public:
        Drink(string name, double priceL, double priceM, double priceS);

        string get_name() const;
        double get_priceL() const;
        double get_priceM() const;
        double get_priceS() const;

        friend ostream& operator << (ostream& out, const Drink& drink);

    private:
        string name;
        double priceL;
        double priceM;
        double priceS;
};

#endif // DRINK_H
