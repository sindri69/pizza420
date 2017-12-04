#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <string>
using namespace std;

class myFunctions /* Here I'll put various functions that'll make the other classes more readable */
{
    public:
        myFunctions();
        virtual ~myFunctions();

        /* Functions that check if string matches line in text-file */
        bool check_LineMatches_PizzaList(string line, int linenum);
        bool check_LineMatches_TypesList(string line, int linenum);
        bool check_LineMatches_ToppingsList(string line, int linenum);
        bool check_LineMatches_DrinksList(string line, int linenum);
        bool check_LineMatches_ExtrasList(string line, int linenum);

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
