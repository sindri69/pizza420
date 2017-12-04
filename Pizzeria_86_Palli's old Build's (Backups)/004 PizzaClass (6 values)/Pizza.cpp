#include "Pizza.h"

/* ATH! The number of values listed here (verbose not counted) are crucial to OrderUI's *const int numberOfValuesInPizzaClass*! Make sure to update when changed! (currently 6 values) */
Pizza::Pizza() {            /* Default Constructor, sets the default values */
    p_size = "L";           /* L/l = Large, M/m = Medium, S/s = Small */
    p_type = "Basic";       /* Basic = plain pizza, FromList = pizza from the administrator's list, Custom = pick your own toppings */
    p_extras = "";          /* Drinks, Bread-sticks etc. */
    p_price = 0;            /* Calculated total price of the pizza */
    p_payedfor = false;     /* Has the pizza been payed for ? (y/n) */
    p_status = 1;           /* 1 = Not-made, 2 = Being made, 3 = Ready, 4 = Delivered */

    verbose = true;         /* Says yes to extra text */
}

Pizza::~Pizza()
{
    //dtor
}

/* Note: �urfum a� setja Pizza:: fyrir framan function */
void Pizza::setVerbose(bool v) {  /* Function sem leyfir okkur a� velja hvort vi� viljum aukatexta e�a ekki */
    verbose = v;
}

/* Note: �urfum ekki a� setja Pizza:: fyrir framan istream og ostream �v� �au eru ekki function, heldur *friends* */
istream& operator >> (istream& in, Pizza& pizza) { /* istream skr�ir d�t � textafilei� */

    if (pizza.verbose) {                           /* Viljum bara aukatexta � skj�inn, ekki � textfilei� */
        cout << "Enter size: ";
    }
    in >> ws;                     /* �essi l�na kemur � veg fyrir a� *enter* s� teki� inn sem gildi, �urfum �etta bara ef vi� notum *getline* */
    getline (in, pizza.p_size);   /* T�kum inn string sem gildi,   Note: g�tum nota� char � sta�inn, �g nota string atm �v� �a� kemur � veg fyrir a� t�lvan tekur vi� helling af values � einu */
    if (pizza.verbose) {
        cout << "Enter type: ";
    }
    in >> ws;
    getline (in, pizza.p_type);

    return in;
}

ostream& operator << (ostream& out, const Pizza& pizza) {       /* ostream les �r textafileinu */

    if (pizza.verbose) {                                        /* H�r byrjar function sem tryggir a� �egar vi� f�um listan f�um vi� Large � sta� L/l, Medium � sta� M/m og Small � sta� S/s */
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
            cout << "Invalid ";                /* atm er "Large" default st�r�in, �annig a� ef bullgildi var gefi� �� les t�lvan �a� bara sem Large */
        }

        cout << pizza.p_type << endl;        /* atm er enginn listi fyir PizzaTypes e�a toppings �annig a� t�lvan les bara �a� string gildi sem var skr�� */
    }
    else {
        out << pizza.p_size << endl;
        out << pizza.p_type << endl;
        out << pizza.p_extras << endl;
        out << pizza.p_price << endl;
        out << pizza.p_payedfor << endl;
        out << pizza.p_status << endl;
    }

    return out;
}
