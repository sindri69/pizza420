#include "Topping.h"

Topping::Topping(string name, double price)
{
    this->name = name;
    this->price = price;
}

string Topping::get_name() const {
    return this->name;
}
double Topping::get_price() const {
    return this->price;
}

ostream& operator << (ostream& out, const Topping& topping) {

    out << topping.name << endl;
    out << topping.price << endl;

    return out;
}
