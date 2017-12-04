#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <string>
using namespace std;

class myFunctions /* Here I'll put various functions that'll make the other classes more readable */
{
    public:
        myFunctions();
        virtual ~myFunctions();

        /* Here the user is asked the question repeatedly until he replies with yes or no */
        bool getAnswer_Yes_Or_No(string question);

        /* Functions that loop until user gives correct input */
        string getCorrectSize();
        string getCorrectTypePre();
        string getCorrectType();
        string getCorrectTopping();
        string getCorrectDrink();
        string getCorrectExtra();

        /* Functions that take string and return number */
        double convert_stringToDouble(string s);
        int convert_stringToInteger(string s);

        /* Makes sure there aren't 2 types of toppings,drinks or extras with the same name */
        /* returns true if they have the same name */
        bool namesake_Typeslist(string newType);
        bool namesake_Topping(string newType);
        bool namesake_Drinks(string newType);
        bool namesake_Extra(string newType);

    protected:

    private:
};

#endif // MYFUNCTIONS_H
