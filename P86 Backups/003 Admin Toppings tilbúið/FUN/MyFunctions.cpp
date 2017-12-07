#include "MyFunctions.h"

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
