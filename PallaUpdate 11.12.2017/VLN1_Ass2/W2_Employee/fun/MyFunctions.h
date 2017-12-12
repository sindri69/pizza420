#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <string>
#include <iostream>
#include <sstream> /// for StringStream in the convert functions
using namespace std;

class MyFunctions
{
    public:
        MyFunctions();

        /// Here we take a string and change all characters to lowercase or uppercase
        string convert_StringToLowerCase(string s);
        string convert_StringToUpperCase(string s);

        /// Here we convert strings to numbers or numbers to strings (note: http://www.cplusplus.com/forum/articles/9645/)
        string convert_DoubleToString(double d);
        string convert_IntegerToString(int i);
        double convert_StringToDouble(string s);
        int convert_StringToInteger(string s);

        /// Here we ask the user a question, and return the answer as a number
        int getAnswer_Integer(string question);
        double getAnswer_Double(string question);

        /// Here the user is asked the question repeatedly until he replies with yes or no
        bool getAnswer_Yes_Or_No(string question);

        /// Here we ask for the month return answer as integer
        int getAnswer_Month(string question);

        /// Here we only ask once and return the answer
        string getAnswer(string question);

        /// Here we ask the user the question repeatedly until he gives a valid answer, we then return the answer, can have up to 15 valid answers
        string getAnswer(string question, string validAnswer);
        string getAnswer(string q, string vA1, string vA2);
        string getAnswer(string q, string vA1, string vA2, string vA3);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12, string vA13);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12, string vA13, string vA14);
        string getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12, string vA13, string vA14, string vA15);

    private:
};

#endif // MYFUNCTIONS_H
