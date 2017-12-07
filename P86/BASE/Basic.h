#ifndef BASIC_H
#define BASIC_H

#include <string>
#include <iostream>
using namespace std;

class Basic
{
    public:
        Basic(double priceL, double priceM, double priceS);

        double get_priceL() const;
        double get_priceM() const;
        double get_priceS() const;

        friend ostream& operator << (ostream& out, const Basic& basic);

    private:
        double priceL;
        double priceM;
        double priceS;
};

#endif // BASIC_H
