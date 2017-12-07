#include "Pizza.h"

Pizza::Pizza(string psize, string ptype, string ptopping, double pprice, bool ppayedfor, int pstatus)
{
    this->psize = psize;
    this->ptype = ptype;
    this->ptopping = ptopping;
    this->pprice = pprice;
    this->ppayedfor = ppayedfor;
    this->pstatus = pstatus;
}

string Pizza::get_psize() const {
    return this->psize;
}
string Pizza::get_ptype() const {
    return this->ptype;
}
string Pizza::get_ptopping() const {
    return this->ptopping;
}
double Pizza::get_pprice() const {
    return this->pprice;
}
bool Pizza::get_ppayedfor() const {
    return this->ppayedfor;
}
int Pizza::get_pstatus() const {
    return this->pstatus;
}

ostream& operator << (ostream& out, const Pizza& pizza) {

    out << pizza.psize << endl;
    out << pizza.ptype << endl;
    out << pizza.ptopping << endl;
    out << pizza.pprice << endl;
    out << pizza.ppayedfor << endl;
    out << pizza.pstatus << endl;

    return out;
}
