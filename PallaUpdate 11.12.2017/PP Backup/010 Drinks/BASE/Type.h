#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <iostream>
using namespace std;

class Type
{
    public:
        Type(string name, double priceL, double priceM, double priceS);

        string get_name() const;
        double get_priceL() const;
        double get_priceM() const;
        double get_priceS() const;

        friend ostream& operator << (ostream& out, const Type& type);

    private:
        string name;
        double priceL;
        double priceM;
        double priceS;
};

#endif // TYPE_H
