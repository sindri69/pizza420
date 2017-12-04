#include "Drinks.h"

Drinks::Drinks()
{
    a_drinks = "";
    a_price = 0.0;
    verbose = true;
}

Drinks::~Drinks()
{
    //dtor
}

void Drinks::setDrinks(string s) {
    a_drinks = s;
}
void Drinks::setPrice(double p) {
    a_price = p;
}
void Drinks::setVerbose(bool v) {
    verbose = v;
}
string Drinks::getDrinks() {
    return a_drinks;
}
double Drinks::getPrice() {
    return a_price;
}
bool Drinks::getVerbose() {
    return verbose;
}

istream& operator >> (istream& in, Drinks& drinks) {

    if (drinks.verbose) {
        cout << "Enter drink: ";
    }
    in >> ws;
    getline (in, drinks.a_drinks);

    if (drinks.verbose) {
        cout << "Enter price: ";
    }
    in >> drinks.a_price;

    return in;
}

ostream& operator << (ostream& out, const Drinks& drinks) {

    if (drinks.verbose) {
        cout << drinks.a_drinks << " (Price: $" << drinks.a_price << ")" << endl;
    }
    else {
        out << drinks.a_drinks << endl;
        out << drinks.a_price << endl;
    }

    return out;
}

