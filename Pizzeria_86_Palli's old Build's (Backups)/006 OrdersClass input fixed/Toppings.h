#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Toppings
{
    public:
        Toppings();
        virtual ~Toppings();

        void setToppings(string s);
        void setPrice(double p);
        void setVerbose(bool v);
        string getToppings();
        double getPrice();
        bool getVerbose();

        friend istream& operator >> (istream& in, Toppings& toppings);
        friend ostream& operator << (ostream& out, const Toppings& toppings);

    protected:

    private:
        string a_toppings;
        double a_price;
        bool verbose;
};

#endif // TOPPINGS_H
