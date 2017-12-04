#include "Extras.h"

Extras::Extras()
{
    a_extras = "";
    a_price = 0.0;
    verbose = true;
}

Extras::~Extras()
{
    //dtor
}

void Extras::setExtras(string s) {
    a_extras = s;
}
void Extras::setPrice(double p) {
    a_price = p;
}
void Extras::setVerbose(bool v) {
    verbose = v;
}
string Extras::getExtras() {
    return a_extras;
}
double Extras::getPrice() {
    return a_price;
}
bool Extras::getVerbose() {
    return verbose;
}

istream& operator >> (istream& in, Extras& extras) {

    if (extras.verbose) {
        cout << "Enter extra: ";
    }
    in >> ws;
    getline (in, extras.a_extras);

    if (extras.verbose) {
        cout << "Enter price: ";
    }
    in >> extras.a_price;

    return in;
}

ostream& operator << (ostream& out, const Extras& extras) {

    if (extras.verbose) {
        cout << extras.a_extras << " (Price: $" << extras.a_price << ")" << endl;
    }
    else {
        out << extras.a_extras << endl;
        out << extras.a_price << endl;
    }

    return out;
}
