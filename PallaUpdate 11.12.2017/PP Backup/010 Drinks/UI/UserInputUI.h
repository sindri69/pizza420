#ifndef USERINPUTUI_H
#define USERINPUTUI_H

#include <string>
#include <iostream>
#include <sstream> /// for StringStream in the convert functions
using namespace std;

class UserInputUI /// This class's job is getting user input, keeps cout & cin in other classes to a minimum :]
{
    public:
        UserInputUI();

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

        /// Here we are checking if the answer is an integer
        bool answerIsInteger(string answer);

        /// Here the user is asked the question repeatedly until he replies with yes or no
        bool getAnswer_Yes_Or_No(string question);

        /// Here we ask a question and return the answer as a string
        string getAnswer(string question);

        /// Here we ask the user the question repeatedly until he gives a valid answer, we then return the answer, can have up to 6 valid answers
        string getAnswer(string question, string validAnswer);
        string getAnswer(string q, string a1, string a2);
        string getAnswer(string q, string a1, string a2, string a3);
        string getAnswer(string q, string a1, string a2, string a3, string a4);
        string getAnswer(string q, string a1, string a2, string a3, string a4, string a5);
        string getAnswer(string q, string a1, string a2, string a3, string a4, string a5, string a6);
};

#endif // USERINPUTUI_H
