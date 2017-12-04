#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <string>
using namespace std;

class MyFunctions /* Here I'll put various functions that'll make the other classes more readable */
{
    public:
        MyFunctions();
        virtual ~MyFunctions();

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

    protected:

    private:
};

#endif // MYFUNCTIONS_H
