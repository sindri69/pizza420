#include "MyFunctions.h"
#include "ReadFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

MyFunctions::MyFunctions()
{
    //ctor
}

MyFunctions::~MyFunctions()
{
    //dtor
}

ReadFunctions fun; /* Functions that read from text-files */

bool MyFunctions::getAnswer_Yes_Or_No(string question) { /* Here the user is asked the question repeatedly until he replies with yes or no */
    string userInput = "";
    while (userInput != "y" && userInput != "Y" && userInput != "yes" && userInput != "Yes" && userInput != "YES" && userInput != "n" && userInput != "N" && userInput != "no" && userInput != "No" && userInput != "NO") {
        cout << question << " ";
        getline(cin,userInput);
    }
    if (userInput == "y" || userInput == "Y" || userInput == "yes" || userInput == "Yes" || userInput == "YES") {
        return true;
    }
    else {
        return false;
    }
}

string MyFunctions::getCorrectSize() {

    bool is_it_the_right_size = false;
    string userInput;

    while (is_it_the_right_size == false) {

        cout << "Enter size (L/M/S) ";
        cin >> userInput;

        if (userInput == "l" || userInput == "L" || userInput == "large" || userInput == "Large" || userInput == "LARGE") {
            userInput = "Large";
            is_it_the_right_size = true;
        }
        else if (userInput == "m" || userInput == "M" || userInput == "medium" || userInput == "Medium" || userInput == "MEDIUM") {
            userInput = "Medium";
            is_it_the_right_size = true;
        }
        else if (userInput == "s" || userInput == "S" || userInput == "small" || userInput == "Small" || userInput == "SMALL") {
            userInput = "Small";
            is_it_the_right_size = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    return userInput;
}

string MyFunctions::getCorrectTypePre() {
    bool is_it_a_valid_type = false;
    string userInput = "";
    if (fun.fileExists_TypesList() && fun.fileExists_ToppingsList() && fun.get_NumberOfLines_TypesList() != 0 && fun.get_NumberOfLines_ToppingsList() != 0) {
        while (!is_it_a_valid_type) {
            cout << "Pick Pizza-Type (B = Basic / C = Custom / M = Pick from Menu) ";
            cin >> userInput;
            if (userInput == "b" || userInput == "B" || userInput == "basic" || userInput == "Basic" || userInput == "BASIC") {
                userInput = "Basic";
                is_it_a_valid_type = true;
            }
            else if (userInput == "c" || userInput == "C" || userInput == "custom" || userInput == "Custom" || userInput == "CUSTOM") {
                userInput = "Custom";
                is_it_a_valid_type = true;
            }
            else if (userInput == "m" || userInput == "M" || userInput == "menu" || userInput == "Menu" || userInput == "MENU") {
                userInput = "Menu";
                is_it_a_valid_type = true;
            }
        }
        return userInput;
    }
    else if (fun.fileExists_TypesList() && fun.get_NumberOfLines_TypesList()) {
        while (!is_it_a_valid_type) {
            cout << "Pick Pizza-Type (B = Basic / M = Pick from Menu) ";
            cin >> userInput;
            if (userInput == "b" || userInput == "B" || userInput == "basic" || userInput == "Basic" || userInput == "BASIC") {
                userInput = "Basic";
                is_it_a_valid_type = true;
            }
            else if (userInput == "m" || userInput == "M" || userInput == "menu" || userInput == "Menu" || userInput == "MENU") {
                userInput = "Menu";
                is_it_a_valid_type = true;
            }
        }
        return userInput;
    }
    else if (fun.fileExists_ToppingsList() && fun.get_NumberOfLines_ToppingsList() != 0) {
        while (!is_it_a_valid_type) {
            cout << "Pick Pizza-Type (B = Basic / C = Custom) ";
            cin >> userInput;
            if (userInput == "b" || userInput == "B" || userInput == "basic" || userInput == "Basic" || userInput == "BASIC") {
                userInput = "Basic";
                is_it_a_valid_type = true;
            }
            else if (userInput == "c" || userInput == "C" || userInput == "custom" || userInput == "Custom" || userInput == "CUSTOM") {
                userInput = "Custom";
                is_it_a_valid_type = true;
            }
        }
        return userInput;
    }
    else {
        return "Basic";
    }
}

string MyFunctions::getCorrectType() {
    bool is_it_a_valid_type = false;
    string userInput = "";

    while (!is_it_a_valid_type) {

        cout << "List of available types:" << endl;
        int j = 1, numoflines = fun.get_NumberOfLines_ToppingsList();
        for (int i = 0; i < (numoflines / 2); i++) {
            cout << fun.get_Line_TypesList(j) << " (Price $";
            j++;
            cout << fun.get_Line_TypesList(j) << ")" << endl;
            j++;
        }
        getline(cin,userInput);
        j = 1;
        for (int i = 0; i < (numoflines / 2); i++) {
            if (!fun.lineMatches_TypesList(userInput,j)) {
                j = j + 2;
            }
            else {
                is_it_a_valid_type = true;
            }
        }
        if (!is_it_a_valid_type) {
            cout << "That type is not on the list, try again" << endl;
        }
    }
    return userInput;
}

string MyFunctions::getCorrectTopping() {
    bool is_it_a_valid_topping = false;
    string userInput;

    while (!is_it_a_valid_topping) {

        cout << "List of available toppings:" << endl;
        int j = 1, numoflines = fun.get_NumberOfLines_ToppingsList();
        for (int i = 0; i < (numoflines / 2); i++) {
            cout << fun.get_Line_ToppingsList(j) << " (Price $";
            j++;
            cout << fun.get_Line_ToppingsList(j) << ")" << endl;
            j++;
        }
        getline(cin,userInput);
        j = 1;
        for (int i = 0; i < (numoflines / 2); i++) {
            if (!fun.lineMatches_ToppingsList(userInput,j)) {
                j = j + 2;
            }
            else {
                is_it_a_valid_topping = true;
            }
        }
        if (!is_it_a_valid_topping) {
            cout << "That topping is not on the list, try again" << endl;
        }
    }
    return userInput;
}
string MyFunctions::getCorrectDrink() {
    bool is_it_a_valid_drink = false;
    string userInput;

    while (!is_it_a_valid_drink) {

        cout << "List of available drinks:" << endl;
        int j = 1, numoflines = fun.get_NumberOfLines_DrinksList();
        for (int i = 0; i < (numoflines / 2); i++) {
            cout << fun.get_Line_DrinksList(j) << " (Price $";
            j++;
            cout << fun.get_Line_DrinksList(j) << ")" << endl;
            j++;
        }
        getline(cin,userInput);
        j = 1;
        for (int i = 0; i < (numoflines / 2); i++) {
            if (!fun.lineMatches_DrinksList(userInput,j)) {
                j = j + 2;
            }
            else {
                is_it_a_valid_drink = true;
            }
        }
        if (!is_it_a_valid_drink) {
            cout << "That drink is not on the list, try again" << endl;
        }
    }
    return userInput;
}
string MyFunctions::getCorrectExtra() {
    bool is_it_a_valid_extra = false;
    string userInput;

    while (!is_it_a_valid_extra) {

        cout << "List of available extras:" << endl;
        int j = 1, numoflines = fun.get_NumberOfLines_ExtrasList();
        for (int i = 0; i < (numoflines / 2); i++) {
            cout << fun.get_Line_ExtrasList(j) << " (Price $";
            j++;
            cout << fun.get_Line_ExtrasList(j) << ")" << endl;
            j++;
        }
        getline(cin,userInput);
        j = 1;
        for (int i = 0; i < (numoflines / 2); i++) {
            if (!fun.lineMatches_ExtrasList(userInput,j)) {
                j = j + 2;
            }
            else {
                is_it_a_valid_extra = true;
            }
        }
        if (!is_it_a_valid_extra) {
            cout << "That extra is not on the list, try again" << endl;
        }
    }
    return userInput;
}

double MyFunctions::convert_stringToDouble(string s) { /* Convert string to Double using <sstream> */
    double result;               /* Double which will contains the result */
    stringstream convert(s);     /* stringstream used for conversion */
    if ( !(convert >> result) )  /* give value to result using characters in the string */
        result = 0;              /* if that fails set result to 0 */
    return result;               /* return result */ /* http://www.cplusplus.com/forum/articles/9645/ */
}
int MyFunctions::convert_stringToInteger(string s) { /* Convert string to Integer using <sstream> */
    int result;                  /* Integer which will contains the result */
    stringstream convert(s);     /* stringstream used for conversion */
    if ( !(convert >> result) )  /* give value to result using characters in the string */
        result = 0;              /* if that fails set result to 0 */
    return result;               /* return result */ /* http://www.cplusplus.com/forum/articles/9645/ */
}
