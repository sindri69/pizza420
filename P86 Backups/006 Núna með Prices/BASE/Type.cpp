#include "Type.h"

Type::Type(string name, double priceL, double priceM, double priceS)
{
    this->name = name;
    this->priceL = priceL;
    this->priceM = priceM;
    this->priceS = priceS;
}

string Type::get_name() const {
    return this->name;
}
double Type::get_priceL() const {
    return this->priceL;
}
double Type::get_priceM() const {
    return this->priceM;
}
double Type::get_priceS() const {
    return this->priceS;
}

ostream& operator << (ostream& out, const Type& type) {

    out << type.name << endl;
    out << type.priceL << endl;
    out << type.priceM << endl;
    out << type.priceS << endl;

    return out;
}
