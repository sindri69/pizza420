#include "Pizza.h"
#include "MyFunctions.h"
#include "ReadFunctions.h"

/* ATH! The number of values listed here (verbose not counted) are crucial to OrderUI's *const int numberOfValuesInPizzaClass*! Make sure to update when changed! (currently 8 values) */
Pizza::Pizza() {            /* Default Constructor, sets the default values */
    p_size = "Large";       /* L = Large, M = Medium, S = Small */
    p_type = "Basic";       /* Basic = plain pizza, FromList = pizza from the administrator's list, Custom = pick your own toppings */
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
void Pizza::setSize(string s) {
    p_size = s;
}
void Pizza::setType(string t) {
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
string Pizza::getSize() {
    return p_size;
}
string Pizza::getType() {
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

istream& operator >> (istream& in, Pizza& pizza) { /* Note to self: Read more about istream vs ifstream */

    MyFunctions myfun; /* Here I call myFunctions, it makes the Pizza Class more readable */
    ReadFunctions fun; /* Here I call readFunctions, it's just like myFunctions but it only has functions for getting values from text-files */

    if (pizza.verbose) {
        string tempSize;
        tempSize = myfun.getCorrectSize(); /* This function makes sure we get the correct userInput */
        pizza.setSize(tempSize);

        pizza.setType(myfun.getCorrectTypePre()); /* This function sets Type to either "Basic", "Custom" or "Menu" */
        if (pizza.getType() == "Menu") {
            pizza.setType(myfun.getCorrectType()); /* This function changes the PizzaType to one from TypesList */
        }
        else if (pizza.getType() == "Custom") {
            pizza.setToppings(myfun.getCorrectTopping()); /* This function gets the correct toppings from ToppingsList */
        }

        string tempDrinks;
        if (fun.fileExists_DrinksList() && fun.get_NumberOfLines_DrinksList() != 0) { /* If the Drinks-file exists, and it's not empty */
            if (myfun.getAnswer_Yes_Or_No("Would you like a drink with your order?")) { /* If the user says yes */
                tempDrinks = myfun.getCorrectDrink(); /* Then we use this function to get valid userInput */
            }
            else { /* If the user said no then we set Drinks to the default (empty string) */
                tempDrinks = pizza.getDrinks();
            }
        }
        else { /* If the Drinks-file does not exist (or is empty) then we set it to the default (empty string) */
            tempDrinks = pizza.getDrinks();
        }
        pizza.setDrinks(tempDrinks);

        string tempExtras;
        if (fun.fileExists_ExtrasList() && fun.get_NumberOfLines_ExtrasList() != 0) { /* If the Extras-file exists, and it's not empty */
            if (myfun.getAnswer_Yes_Or_No("Would you like any extras with your order?")) { /* If the user says yes */
                tempExtras == myfun.getCorrectExtra(); /* Then we use this function to get valid userInput */
            }
            else {  /* If the user said no then we set Extras to the default (empty string) */
                tempExtras = pizza.getExtras();
            }
        }
        else { /* If the Extras-file does not exist (or is empty) then we set it to the default (empty string) */
            tempExtras = pizza.getExtras();
        }
        pizza.setExtras(tempExtras);
    }
    else { /* This code may be useless considering that we have a different method to see list (read_List) */
        getline (in, pizza.p_size);
        getline (in, pizza.p_type);
        getline (in, pizza.p_toppings);
        getline (in, pizza.p_drinks);
        getline (in, pizza.p_extras);
        in >> pizza.p_price;
        in >> pizza.p_payedfor;
        in >> pizza.p_status;
    }

/*  These functions don't exist yes!
    pizza.p_price = myfunction.getCorrectPrice();
    pizza.p_payedfor = myfunction.getCorrectPayedFor();
    pizza.p_status = myfunction.getCorrectStatus();
*/

    return in;
}

/* ATH! This function adds the values correctly to the file, but does not read from it correctly, another function will possibly be used instead */
ostream& operator << (ostream& out, const Pizza& pizza) {

    if (pizza.verbose) { /* This method does not work ATM, and it is likely obsolete because of a new method for printing lists (read_list) */

        cout << "Size (" << pizza.p_size << ") Type (" << pizza.p_type << ") Toppings (" << pizza.p_toppings;
        cout << ") Drinks (" << pizza.p_drinks << ") Extras (" << pizza.p_extras << ") Price (" << pizza.p_price;
        cout << ") Payedfor (" << pizza.p_payedfor << ") Status (" << pizza.p_status << ")" << endl;
    }
    else { /* This adds all the values to the textFile */
        out << pizza.p_size << endl;
        out << pizza.p_type << endl;
        out << pizza.p_toppings << endl;
        out << pizza.p_drinks << endl;
        out << pizza.p_extras << endl;
        out << pizza.p_price << endl;
        out << pizza.p_payedfor << endl;
        out << pizza.p_status << endl;
    }

    return out;
}
