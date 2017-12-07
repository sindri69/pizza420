#include "Type.h"

Type::Type(string name, double price)
{
    this->name = name;
    this->price = price;
}

string Type::get_name() const {
    return this->name;
}
double Type::get_price() const {
    return this->price;
}

ostream& operator << (ostream& out, const Type& type) {

    out << type.name << ", " << type.price << endl;

    return out;
}
