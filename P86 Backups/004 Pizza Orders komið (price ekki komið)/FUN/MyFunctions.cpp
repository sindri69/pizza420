#include "MyFunctions.h"
#include "ReadFunctions.h"

MyFunctions::MyFunctions()
{
    //ctor
}

string MyFunctions::convert_DoubleToString(double d) {
    string result;
    stringstream convert;
    convert << d;
    result = convert.str();
    return result;
}
string MyFunctions::convert_IntegerToString(int i) {
    string result;
    stringstream convert;
    convert << i;
    result = convert.str();
    return result;
}
double MyFunctions::convert_StringToDouble(string s) {
    double result;
    stringstream convert(s);
    if ( !(convert >> result) ) {
        result = 0; // if convert fails, result is 0
    }
    return result;
}
int MyFunctions::convert_StringToInteger(string s) {
    double result;
    stringstream convert(s);
    if ( !(convert >> result) ) {
        result = 0; // if convert fails, result is 0
    }
    return result;
}

int MyFunctions::getAnswer_Integer(string question) {
    string answer;
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    return convert_StringToInteger(answer);
}
double MyFunctions::getAnswer_Double(string question) {
    string answer;
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    return convert_StringToDouble(answer);
}

bool MyFunctions::getAnswer_Yes_Or_No(string question) { /* Here the user is asked the question repeatedly until he replies with yes or no */
    string answer = getAnswer(question,"y","Y","yes","Yes","YES","n","N","no","No","NO");
    if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES") {
        return true;
    }
    else {
        return false;
    }
}

string MyFunctions::getAnswer(string question) { /* Here the user is asked the question once and we then return the answer */
    string answer = "";
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    return answer;
}

string MyFunctions::getAnswer(string question, string validAnswer) { /* Here the user is asked the question repeatedly until he replies with a validAnswer, we then return the answer */
    string answer = "";
    while (answer != validAnswer) {
        cout << question << " ";
        cin >> ws;
        getline(cin,answer);
    }
    return answer;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2) {
    string a = "";
    while (a != vA1 && a != vA2) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9 && a != vA10) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9 && a != vA10 && a != vA11) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9 && a != vA10 && a != vA11 && a != vA12) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12, string vA13) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9 && a != vA10 && a != vA11 && a != vA12 && a != vA13) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12, string vA13, string vA14) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9 && a != vA10 && a != vA11 && a != vA12 && a != vA13 && a != vA14) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}
string MyFunctions::getAnswer(string q, string vA1, string vA2, string vA3, string vA4, string vA5, string vA6, string vA7, string vA8, string vA9, string vA10, string vA11, string vA12, string vA13, string vA14, string vA15) {
    string a = "";
    while (a != vA1 && a != vA2 && a != vA3 && a != vA4 && a != vA5 && a != vA6 && a != vA7 && a != vA8 && a != vA9 && a != vA10 && a != vA11 && a != vA12 && a != vA13 && a != vA14 && a != vA15) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
    }
    return a;
}

string MyFunctions::getCorrectSize() {
    cout << endl;
    string answer = getAnswer("Size (L = Large / M = Medium / S = Small):","l","L","large","Large","LARGE","m","M","medium","Medium","MEDIUM","s","S","small","Small","SMALL");
    if (answer == "l" || answer == "L" || answer == "large" || answer == "Large" || answer == "LARGE") {
        return "Large";
    }
    else if (answer == "m" || answer == "M" || answer == "medium" || answer == "Medium" || answer == "MEDIUM") {
        return "Medium";
    }
    else {
        return "Small";
    }
}
string MyFunctions::getCorrectType() {
    ReadFunctions fun;

    if (fun.fileNotEmpty_type() && fun.fileNotEmpty_topping()) { /// If the Types-List and Toppings-List are both available we can offer Basic, Custom and Menu
        cout << endl;
        string type = getAnswer("Type (B = Basic / C = Custom (choose own toppings) / M = Pick from Menu)","b","B","basic","Basic","BASIC","c","C","custom","Custom","CUSTOM","m","M","menu","Menu","MENU");
        if (type == "b" || type == "B" || type == "basic" || type == "Basic" || type == "BASIC") {
            return "Basic";
        }
        if (type == "c" || type == "C" || type == "custom" || type == "Custom" || type == "CUSTOM") {
            return "Custom";
        }
    }
    else if (fun.fileNotEmpty_topping()) { /// If the Toppings-List is available then we can offer Basic and Custom
        string type = getAnswer("Type (B = Basic / C = Custom (choose own toppings)):","b","B","basic","Basic","BASIC","c","C","custom","Custom","CUSTOM");
        if (type == "b" || type == "B" || type == "basic" || type == "Basic" || type == "BASIC") {
            return "Basic";
        }
        return "Custom";
    }
    else if (fun.fileNotEmpty_type()) { /// If the Types-List is available then we can offer Basic and Menu
        string type = getAnswer("Type (B = Basic / M = Pick from Menu):","b","B","basic","Basic","BASIC","m","M","menu","Menu","MENU");
        if (type == "b" || type == "B" || type == "basic" || type == "Basic" || type == "BASIC") {
            return "Basic";
        }
    }
    else {
        return "Basic"; /// If the Types-List and Toppings-List are both unavailable then we set the Type to "Basic"
    }
    cout << endl;
    while (true) { /// If the user wants to pick a pizza from the menu then we print out the list of valid Types and only accept input which matches pizza from the Types-List
        cout << "List of Pizza-Types:" << endl;
        fun.read_fancy_type();
        cout << endl;
        string answer = getAnswer("Which Pizza-Type would you like?");
        if (fun.check_TypeExists_type(answer)) {
            return answer;
        }
        cout << endl;
        cout << "That is not on the list, try again" << endl;
        cout << endl;
    }
}
string MyFunctions::getCorrectTopping(string ptype) {
    ReadFunctions fun;

    if (ptype == "Custom") {
        cout << endl;
        while (true) {
            cout << "List of Pizza-Toppings:" << endl;
            fun.read_fancy_topping();
            cout << endl;
            string answer = getAnswer("Which Pizza-Topping would you like?");
            if (fun.check_ToppingExists_topping(answer)) {
                return answer;
            }
            cout << endl;
            cout << "That is not on the list, try again" << endl;
            cout << endl;
        }
    }
    return ""; /// If the Pizza-Type is not Custom, then the user does not pick his own toppings
}
double MyFunctions::getCorrectPrice(string psize, string ptype, string ptopping) {
    return 42.69; /// make function later ...
}
