#ifndef PIZZA_H
#define PIZZA_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class Pizza                     /* í .h skrám eru private gildi skráð og public functions *declared*, public function eru implementuð í .cpp */
{
    public:
        Pizza();
        virtual ~Pizza();

        void setVerbose(bool v);

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);

    protected:

    /* ATH! The number of values listed here (verbose not counted) are crucial to OrderUI's *const int numberOfValuesInPizzaClass*! Make sure to update when changed! (currently 6 values) */
    private:
        string p_size;    /* L/l = Large, M/m = Medium, S/s = Small */
        string p_type;    /* Basic = plain pizza, FromList = pizza from the administrator's list, Custom = pick your own toppings */
        string p_extras;  /* Drinks, Bread-sticks etc. */
        double p_price;   /* Calculated total price of the pizza */
        bool p_payedfor;  /* Has the pizza been payed for ? (y/n) */
        int p_status;     /* 1 = Not-made, 2 = Being made, 3 = Ready, 4 = Delivered */

        bool verbose;     /* True = Extra-text included, False = Extra-text not included */
};

#endif // PIZZA_H
