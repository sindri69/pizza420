#include "Basic.h"

Basic::Basic(double priceL, double priceM, double priceS) {
    this->priceL = priceL;
    this->priceM = priceM;
    this->priceS = priceS;
}

double Basic::get_priceL() const {
    return this->priceL;
}
double Basic::get_priceM() const {
    return this->priceM;
}
double Basic::get_priceS() const {
    return this->priceS;
}

ostream& operator << (ostream& out, const Basic& basic) {

    out << basic.priceL << endl;
    out << basic.priceM << endl;
    out << basic.priceS << endl;

    return out;
}
