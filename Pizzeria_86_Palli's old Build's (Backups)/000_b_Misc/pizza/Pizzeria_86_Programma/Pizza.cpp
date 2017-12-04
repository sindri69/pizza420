#include "Pizza.h"

Pizza::Pizza()
{
    p_size = "L";
    p_type = "Margherita";
    verbose = true;
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::setVerbose(bool v) {
    verbose = v;
}

istream& operator >> (istream& in, Pizza& pizza) {
    if (pizza.verbose) {
        cout << "Enter size: ";
    }
    in >> ws;
    getline (in, pizza.p_size);

    if (pizza.verbose) {
        cout << "Enter type: ";
    }
    in >> ws;
    getline (in, pizza.p_type);

    return in;
}

ostream& operator << (ostream& out, const Pizza& pizza) {

    if (pizza.verbose) {
        if (pizza.p_size == "s" || pizza.p_size == "S") {
            cout << "Small ";
        }
        else if (pizza.p_size == "m" || pizza.p_size == "M") {
            cout << "Medium ";
        }
        else if (pizza.p_size == "l" || pizza.p_size == "L") {
            cout << "Large ";
        }
        else {
            cout << "Large ";
        }
        cout << pizza.p_type << endl;
    }
    else {
        out << pizza.p_size << endl;
        out << pizza.p_type << endl;
    }

    return out;
}
