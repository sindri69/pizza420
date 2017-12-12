#include "Extra.h"

Extra::Extra(string name, double priceL, double priceM, double priceS) {
    this->name = name;
    this->priceL = priceL;
    this->priceM = priceM;
    this->priceS = priceS;
}

string Extra::get_name() const {
    return this->name;
}
double Extra::get_priceL() const {
    return this->priceL;
}
double Extra::get_priceM() const {
    return this->priceM;
}
double Extra::get_priceS() const {
    return this->priceS;
}

ostream& operator << (ostream& out, const Extra& extra) {

    out << extra.name << endl;
    out << extra.priceL << endl;
    out << extra.priceM << endl;
    out << extra.priceS << endl;

    return out;
}
