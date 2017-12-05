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

        void setDrinks(string s);
        void setPrice(double p);
        void setVerbose(bool v);
        string getDrinks();
        double getPrice();
        bool getVerbose();

        friend istream& operator >> (istream& in, Drinks& drinks);
        friend ostream& operator << (ostream& out, const Drinks& drinks);

    protected:

    private:
        string a_drinks;
        double a_price;
        bool verbose;
};

#endif // DRINKS_H
