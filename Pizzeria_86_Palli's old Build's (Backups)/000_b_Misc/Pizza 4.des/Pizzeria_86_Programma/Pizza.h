#ifndef PIZZA_H
#define PIZZA_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        /* Functions that set private values */
        void setSize(string s);
        void setType(string t);
        void setToppings(string t);
        void setDrinks(string d);
        void setExtras(string e);
        void setPrice(double p);
        void setPayedFor(bool p);
        void setStatus(int s);
        void setVerbose(bool v);

        /* Functions that get private values */
        string getSize();
        string getType();
        string getToppings();
        string getDrinks();
        string getExtras();
        double getPrice();
        bool getPayedFor();
        int getStatus();
        bool getVerbose();

        /* Functions that add to and read from PizzaList */
        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);

    protected:

    /* ATH! The number of values listed here are crucial to OrderUI's *const int numberOfValuesInPizzaClass* Make sure to update when changed! (currently 8 values) */
    private:
        string p_size;
        string p_type;
        string p_toppings;
        string p_drinks;
        string p_extras;
        double p_price;
        bool p_payedfor;
        int p_status;     /* 1 = Not-made, 2 = Being made, 3 = Ready, 4 = Delivered */
        bool verbose;
};

#endif // PIZZA_H
