#include "MyFunctions.h"

MyFunctions::MyFunctions()
{
    //ctor
}

string MyFunctions::convert_StringToLowerCase(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

string MyFunctions::convert_StringToUpperCase(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
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

int MyFunctions::getAnswer_Month(string question) {
    string answer;
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    if (answer == "1" || answer == "2" || answer == "3" || answer == "4" || answer == "5" || answer == "6" || answer == "7" || answer == "8" || answer == "9" || answer == "10" || answer == "11" || answer == "12") {
        return convert_StringToInteger(answer);
    }
    answer = convert_StringToLowerCase(answer);
    if (answer == "january" || answer == "januar" || answer == "janua" || answer == "janu" || answer == "jan") {
        return 1;
    }
    else if (answer == "february" || answer == "februar" || answer == "februa" || answer == "febru" || answer == "febr" || answer == "feb") {
        return 2;
    }
    else if (answer == "march" || answer == "marc" || answer == "mar" || answer == "mars") {
        return 3;
    }
    else if (answer == "april" || answer == "apri" || answer == "apr") {
        return 4;
    }
    else if (answer == "may") {
        return 5;
    }
    else if (answer == "june" || answer == "jun") {
        return 6;
    }
    else if (answer == "july" || answer == "jul") {
        return 7;
    }
    else if (answer == "august" || answer == "augus" || answer == "augu" || answer == "aug") {
        return 8;
    }
    else if (answer == "september" || answer == "septembe" || answer == "septemb" || answer == "septem" || answer == "septe" || answer == "sept" || answer == "sep") {
        return 9;
    }
    else if (answer == "october" || answer == "octobe" || answer == "octob" || answer == "octo" || answer == "oct") {
        return 10;
    }
    else if (answer == "november" || answer == "novembe" || answer == "novemb" || answer == "novem" || answer == "nove" || answer == "nov") {
        return 11;
    }
    else if (answer == "december" || answer == "decembe" || answer == "decemb" || answer == "decem" || answer == "dece" || answer == "dec") {
        return 12;
    }
    else {
        return 0;
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
