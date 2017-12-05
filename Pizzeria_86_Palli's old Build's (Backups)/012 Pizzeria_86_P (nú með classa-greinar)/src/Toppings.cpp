#include "Toppings.h"

Toppings::Toppings()
{
    a_toppings = "";
    a_price = 0.0;
    verbose = true;
}

Toppings::~Toppings()
{
    //dtor
}

void Toppings::setToppings(string s) {
    a_toppings = s;
}
void Toppings::setPrice(double p) {
    a_price = p;
}
void Toppings::setVerbose(bool v) {
    verbose = v;
}
string Toppings::getToppings() {
    return a_toppings;
}
double Toppings::getPrice() {
    return a_price;
}
bool Toppings::getVerbose() {
    return verbose;
}

istream& operator >> (istream& in, Toppings& toppings) {

    if (toppings.verbose) {
        cout << "Enter topping: ";
    }
    in >> ws;
    getline (in, toppings.a_toppings);

    if (toppings.verbose) {
        cout << "Enter price: ";
    }
    in >> toppings.a_price;

    return in;
}

ostream& operator << (ostream& out, const Toppings& toppings) {

    if (toppings.verbose) {
        cout << toppings.a_toppings << " (Price: $" << toppings.a_price << ")" << endl;
    }
    else {
        out << toppings.a_toppings << endl;
        out << toppings.a_price << endl;
    }

    return out;
}
