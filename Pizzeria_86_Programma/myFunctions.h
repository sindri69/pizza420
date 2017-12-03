#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <string>
using namespace std;

class myFunctions /* Here I'll put various functions that'll make the other classes more readable */
{
    public:
        myFunctions();
        virtual ~myFunctions();

        /* Function that takes userInput and does not accept anything else than an integer from 1 to 9 */
        int is_it_integer();

        /* Functions that loop until user gives correct input */
        char getCorrectSize();
        char getCorrectType();
        string getCorrectTopping();

        /* Functions that take string and return number */
        double convert_stringToDouble(string s);
        int convert_stringToInteger(string s);

    protected:

    private:
};

#endif // MYFUNCTIONS_H
