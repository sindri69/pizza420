#ifndef EXTRA_H
#define EXTRA_H

#include <string>
#include <iostream>
using namespace std;

class Extra
{
    public:
        Extra(string name, double priceL, double priceM, double priceS);

        string get_name() const;
        double get_priceL() const;
        double get_priceM() const;
        double get_priceS() const;

        friend ostream& operator << (ostream& out, const Extra& extra);

    private:
        string name;
        double priceL;
        double priceM;
        double priceS;
};

#endif // EXTRA_H
