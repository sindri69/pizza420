#ifndef DRINKS_H
#define DRINKS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Drinks
{
    public:
        Drinks();
        virtual ~Drinks();

        /* Functions that either get or set the private values */
        void setDrinks(string s);
        void setPrice(double p);
        void setVerbose(bool v);
        string getDrinks();
        double getPrice();
        bool getVerbose();

        /* Functions used to read from and add to DrinksList */
        friend istream& operator >> (istream& in, Drinks& drinks);
        friend ostream& operator << (ostream& out, const Drinks& drinks);

    protected:

    private:
        string a_drinks;
        double a_price;
        bool verbose;
};

#endif // DRINKS_H
