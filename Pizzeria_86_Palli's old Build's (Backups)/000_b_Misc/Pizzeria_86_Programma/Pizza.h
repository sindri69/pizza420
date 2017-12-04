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

        void setSize(char s);
        void setType(char t);
        void setToppings(string t);
        void setDrinks(string d);
        void setExtras(string e);
        void setPrice(double p);
        void setPayedFor(bool p);
        void setStatus(int s);

        void setVerbose(bool v);

        char getSize();
        char getType();
        string getToppings();
        string getDrinks();
        string getExtras();
        double getPrice();
        bool getPayedFor();
        int getStatus();

        bool getVerbose();

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);

    protected:

    /* ATH! The number of values listed here are crucial to OrderUI's *const int numberOfValuesInPizzaClass*! Make sure to update when changed! (currently 8 values) */
    private:
        char p_size;       /* L = Large, M = Medium, S = Small */
        char p_type;       /* Basic = plain pizza, FromList = pizza from the administrator's list, Custom = pick your own toppings */
        string p_toppings; /* From Administrator's List */
        string p_drinks;   /* Drinks */
        string p_extras;   /* Bread-sticks etc. */
        double p_price;    /* Calculated total price of the pizza */
        bool p_payedfor;   /* Has the pizza been payed for ? (y/n) */
        int p_status;      /* 1 = Not-made, 2 = Being made, 3 = Ready, 4 = Delivered */

        bool verbose;           /* True = Extra-text included, False = Extra-text not included */
};

#endif // PIZZA_H
