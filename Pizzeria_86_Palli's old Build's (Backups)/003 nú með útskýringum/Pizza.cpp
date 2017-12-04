#include "Pizza.h"

Pizza::Pizza() {            /* Default smiðurinn, setur default value-in */
    p_size = "L";           /* L fyir Large */
    p_type = "Margherita";  /* Margherita = Engin toppings */
    verbose = true;         /* Segjir já, við aukatexta */
}

Pizza::~Pizza()
{
    //dtor
}

/* Note: Þurfum að setja Pizza:: fyrir framan function */
void Pizza::setVerbose(bool v) {  /* Function sem leyfir okkur að velja hvort við viljum aukatexta eða ekki */
    verbose = v;
}

/* Note: Þurfum ekki að setja Pizza:: fyrir framan istream og ostream því þau eru ekki function, heldur *friends* */
istream& operator >> (istream& in, Pizza& pizza) { /* istream skráir dót í textafileið */
    if (pizza.verbose) {                           /* Viljum bara aukatexta á skjáinn, ekki í textfileið */
        cout << "Enter size: ";
    }
    in >> ws;                     /* Þessi lína kemur í veg fyrir að *enter* sé tekið inn sem gildi, þurfum þetta bara ef við notum *getline* */
    getline (in, pizza.p_size);   /* Tökum inn string sem gildi,   Note: gætum notað char í staðinn, ég nota string atm því það kemur í veg fyrir að tölvan tekur við helling af values í einu */
    if (pizza.verbose) {
        cout << "Enter type: ";
    }
    in >> ws;
    getline (in, pizza.p_type);

    return in;
}

ostream& operator << (ostream& out, const Pizza& pizza) {       /* ostream les úr textafileinu */

    if (pizza.verbose) {                                        /* Hér byrjar function sem tryggir að þegar við fáum listan fáum við Large í stað L/l, Medium í stað M/m og Small í stað S/s */
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
            cout << "Large ";                /* atm er "Large" default stærðin, þannig að ef bullgildi var gefið þá les tölvan það bara sem Large */
        }

        cout << pizza.p_type << endl;        /* atm er enginn listi fyir PizzaTypes eða toppings þannig að tölvan les bara það string gildi sem var skráð */
    }
    else {
        out << pizza.p_size << endl;
        out << pizza.p_type << endl;
    }

    return out;
}
