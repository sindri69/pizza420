#include "Drink.h"

Drink::Drink(string name, double priceL, double priceM, double priceS) {
    this->name = name;
    this->priceL = priceL;
    this->priceM = priceM;
    this->priceS = priceS;
}

string Drink::get_name() const {
    return this->name;
}
double Drink::get_priceL() const {
    return this->priceL;
}
double Drink::get_priceM() const {
    return this->priceM;
}
double Drink::get_priceS() const {
    return this->priceS;
}

ostream& operator << (ostream& out, const Drink& drink) {

    out << drink.name << endl;
    out << drink.priceL << endl;
    out << drink.priceM << endl;
    out << drink.priceS << endl;

    return out;
}
