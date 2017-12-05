#include "Pizza.h"
#include "myFunctions.h"

/* ATH! The number of values listed here (verbose not counted) are crucial to OrderUI's *const int numberOfValuesInPizzaClass*! Make sure to update when changed! (currently 8 values) */
Pizza::Pizza() {            /* Default Constructor, sets the default values */
    p_size = 'L';           /* L = Large, M = Medium, S = Small */
    p_type = 'B';           /* Basic = plain pizza, FromList = pizza from the administrator's list, Custom = pick your own toppings */
    p_toppings = "";        /* If Pizza-type is Custom, pick From Administrator's List */
    p_drinks = "";          /* Drinks */
    p_extras = "";          /* Bread-sticks etc. */
    p_price = 0.0;          /* Calculated total price of the pizza */
    p_payedfor = false;     /* Has the pizza been payed for ? (y/n) */
    p_status = 1;           /* 1 = Not-made, 2 = Being made, 3 = Ready, 4 = Delivered */

    verbose = true;
}

Pizza::~Pizza()
{
    //dtor
}

/* Functions that set the private values when called */
void Pizza::setSize(char s) {
    p_size = s;
}
void Pizza::setType(char t) {
    p_type = t;
}
void Pizza::setToppings(string t) {
    p_toppings = t;
}
void Pizza::setDrinks(string d) {
    p_drinks = d;
}
void Pizza::setExtras(string e) {
    p_extras = e;
}
void Pizza::setPrice(double p) {
    p_price = p;
}
void Pizza::setPayedFor(bool p) {
    p_payedfor = p;
}
void Pizza::setStatus(int s) {
    p_status = s;
}
void Pizza::setVerbose(bool v) {
    verbose = v;
}

/* Functions that tell us the private values */
char Pizza::getSize() {
    return p_size;
}
char Pizza::getType() {
    return p_type;
}
string Pizza::getToppings() {
    return p_toppings;
}
string Pizza::getDrinks() {
    return p_drinks;
}
string Pizza::getExtras() {
    return p_extras;
}
double Pizza::getPrice() {
    return p_price;
}
bool Pizza::getPayedFor() {
    return p_payedfor;
}
int Pizza::getStatus() {
    return p_status;
}
bool Pizza::getVerbose() {
    return verbose;
}

/* Note: Þurfum ekki að setja Pizza:: fyrir framan istream og ostream því þau eru ekki function, heldur *friends* */
istream& operator >> (istream& in, Pizza& pizza) { /* istream skráir dót í textafileið */

    myFunctions myfunction; /* Here I call myFunctions */

    char tempSize;
    if (pizza.verbose) {
        tempSize = myfunction.getCorrectSize(); /* Here I use myFunctions to make the pizzaClass more readable */
    }
    pizza.setSize(tempSize);

    char tempType;
    if (pizza.verbose) {
        tempType = myfunction.getCorrectType();
    }
    pizza.setType(tempType);

    if (pizza.getType() == 'C') {
        string tempTopping;
        if (pizza.verbose) {
            tempTopping = myfunction.getCorrectTopping();
        }
        pizza.setToppings(tempTopping);
    }

/*  pizza.p_toppings = myfunction.getCorrectToppings();
    pizza.p_extras = myfunction.getCorrectExtras();
    pizza.p_price = myfunction.getCorrectPrice();
    pizza.p_payedfor = myfunction.getCorrectPayedFor();
    pizza.p_status = myfunction.getCorrectStatus();
*/

    return in;
}

/* ATH! Þetta function skráir hlutina rétt en les ekki rétt úr fileinu */
ostream& operator << (ostream& out, const Pizza& pizza) {       /* ostream les úr textafileinu */

    if (pizza.verbose) {                                        /* Hér byrjar function sem tryggir að þegar við fáum listan fáum við Large í stað L, Medium í stað M og Small í stað S */

        cout << "Size (" << pizza.p_size << ") Type (" << pizza.p_type << ") Toppings (" << pizza.p_toppings;
        cout << ") Extras (" << pizza.p_extras << ") Pride (" << pizza.p_price << ") Payedfor (" << pizza.p_payedfor;
        cout << ") Status (" << pizza.p_status << ")" << endl;
    }
    else { /* This adds all the values to the textFile */
        out << pizza.p_size << endl;
        out << pizza.p_type << endl;
        out << pizza.p_toppings << endl;
        out << pizza.p_extras << endl;
        out << pizza.p_price << endl;
        out << pizza.p_payedfor << endl;
        out << pizza.p_status << endl;
    }

    return out;
}
