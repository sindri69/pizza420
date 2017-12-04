#include "Types.h"
#include "ReadFunctions.h"
#include "MyFunctions.h"

Types::Types()
{
    a_types = "";
    a_price = 0.0;
    verbose = true;
}

Types::~Types()
{
    //dtor
}

void Types::setTypes(string s) {
    a_types = s;
}
void Types::setPrice(double p) {
    a_price = p;
}
void Types::setVerbose(bool v) {
    verbose = v;
}
string Types::getTypes() {
    return a_types;
}
double Types::getPrice() {
    return a_price;
}
bool Types::getVerbose() {
    return verbose;
}

istream& operator >> (istream& in, Types& types) {

    if (types.verbose) {
        cout << "Enter type: ";
    }
    in >> ws;
    getline (in, types.a_types);

    if (types.verbose) {
        cout << "Enter price: ";
    }
    in >> types.a_price;

    return in;
}

ostream& operator << (ostream& out, const Types& types) {

    if (types.verbose) {
        cout << types.a_types << " (Price: $" << types.a_price << ")" << endl;
    }
    else {
        out << types.a_types << endl;
        out << types.a_price << endl;
    }

    return out;
}
