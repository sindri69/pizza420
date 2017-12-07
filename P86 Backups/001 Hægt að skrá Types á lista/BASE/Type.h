#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <iostream>
using namespace std;

class Type
{
    public:
        Type(string name, double price);

        string get_name() const;
        double get_price() const;

        friend ostream& operator << (ostream& out, const Type& type);

    private:
        string name;
        double price;
};

#endif // TYPE_H
