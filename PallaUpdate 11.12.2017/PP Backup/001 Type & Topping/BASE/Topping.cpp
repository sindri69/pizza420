#include "Topping.h"

Topping::Topping(string name, double priceL, double priceM, double priceS) {
    this->name = name;
    this->priceL = priceL;
    this->priceM = priceM;
    this->priceS = priceS;
}

string Topping::get_name() const {
    return this->name;
}
double Topping::get_priceL() const {
    return this->priceL;
}
double Topping::get_priceM() const {
    return this->priceS;
}
double Topping::get_priceS() const {
    return this->priceS;
}

ostream& operator << (ostream& out, const Topping& topping) {

    out << topping.name << endl;
    out << topping.priceL << endl;
    out << topping.priceM << endl;
    out << topping.priceS << endl;

    return out;
}
