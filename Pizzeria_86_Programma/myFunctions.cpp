#include "myFunctions.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

myFunctions::myFunctions()
{
    //ctor
}

myFunctions::~myFunctions()
{
    //dtor
}

int myFunctions::is_it_integer() {

    bool is_it_integer = false;
    int LegitInput;
    string userInput;

    while (is_it_integer == false) {

        cout << "Write an integer between 1 and 9 ";
        cin >> userInput;

        if (userInput == "1") {
            LegitInput = 1;
            is_it_integer = true;
        }
        else if (userInput == "2") {
            LegitInput = 2;
            is_it_integer = true;
        }
        else if (userInput == "3") {
            LegitInput = 3;
            is_it_integer = true;
        }
        else if (userInput == "4") {
            LegitInput = 4;
            is_it_integer = true;
        }
        else if (userInput == "5") {
            LegitInput = 5;
            is_it_integer = true;
        }
        else if (userInput == "6") {
            LegitInput = 6;
            is_it_integer = true;
        }
        else if (userInput == "7") {
            LegitInput = 7;
            is_it_integer = true;
        }
        else if (userInput == "8") {
            LegitInput = 8;
            is_it_integer = true;
        }
        else if (userInput == "9") {
            LegitInput = 9;
            is_it_integer = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    return LegitInput;
}

char myFunctions::getCorrectSize() {

    bool is_it_the_right_size = false;
    char LegitInput;
    string userInput;

    while (is_it_the_right_size == false) {

        cout << "Enter size (L/M/S) ";
        cin >> userInput;

        if (userInput == "l" || userInput == "L" || userInput == "large" || userInput == "Large" || userInput == "LARGE") {
            LegitInput = 'L';
            is_it_the_right_size = true;
        }
        else if (userInput == "m" || userInput == "M" || userInput == "medium" || userInput == "Medium" || userInput == "MEDIUM") {
            LegitInput = 'M';
            is_it_the_right_size = true;
        }
        else if (userInput == "s" || userInput == "S" || userInput == "small" || userInput == "Small" || userInput == "SMALL") {
            LegitInput = 'S';
            is_it_the_right_size = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    return LegitInput;
}

char myFunctions::getCorrectType() {

    bool is_it_the_right_type = false;
    char LegitInput;
    string userInput;

    while (is_it_the_right_type == false) {

        cout << "Enter type (B = Basic / C = Custom / F = From List) ";
        cin >> userInput;

        if (userInput == "b" || userInput == "B" || userInput == "basic" || userInput == "Basic" || userInput == "BASIC") {
            LegitInput = 'B';
            is_it_the_right_type = true;
        }
        else if (userInput == "c" || userInput == "C" || userInput == "custom" || userInput == "Custom" || userInput == "CUSTOM") {
            LegitInput = 'C';
            is_it_the_right_type = true;
        }
        else if (userInput == "f" || userInput == "F" || userInput == "fromlist" || userInput == "FromList" || userInput == "FROMLIST") {
            LegitInput = 'F';
            is_it_the_right_type = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    return LegitInput;
}

string myFunctions::getCorrectTopping() {

    bool is_it_a_valid_topping = false;
    string LegitInput;
    string userInput;

    while (is_it_a_valid_topping == false) {

        cout << "Which topping would you like? (Pepperoni / Piparostur) ";
        cin >> userInput;

        if (userInput == "Pepperoni") {
            LegitInput = "Pepperoni";
            is_it_a_valid_topping = true;
        }
        else if (userInput == "Piparostur") {
            LegitInput = "Piparostur";
            is_it_a_valid_topping = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    return LegitInput;
}

double myFunctions::convert_stringToDouble(string s) { /* Convert string to Double using <sstream> */
    double result;               /* Double which will contains the result */
    stringstream convert(s);     /* stringstream used for conversion */
    if ( !(convert >> result) )  /* give value to result using characters in the string */
        result = 0;              /* if that fails set result to 0 */
    return result;               /* return result */ /* http://www.cplusplus.com/forum/articles/9645/ */
}
int myFunctions::convert_stringToInteger(string s) { /* Convert string to Integer using <sstream> */
    int result;                  /* Integer which will contains the result */
    stringstream convert(s);     /* stringstream used for conversion */
    if ( !(convert >> result) )  /* give value to result using characters in the string */
        result = 0;              /* if that fails set result to 0 */
    return result;               /* return result */ /* http://www.cplusplus.com/forum/articles/9645/ */
}
