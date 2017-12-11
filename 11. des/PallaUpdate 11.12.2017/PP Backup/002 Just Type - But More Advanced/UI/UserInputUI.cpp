#include "UserInputUI.h"

UserInputUI::UserInputUI() { }

string UserInputUI::convert_StringToLowerCase(string s) { /// Here we convert string to lowercase
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
string UserInputUI::convert_StringToUpperCase(string s) { /// Here we convert string to uppercase
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}
string UserInputUI::convert_DoubleToString(double d) { /// Here we convert a double to a string
    string result;
    stringstream convert;
    convert << d;
    result = convert.str();
    return result;
}
string UserInputUI::convert_IntegerToString(int i) { /// Here we convert an integer to a string
    string result;
    stringstream convert;
    convert << i;
    result = convert.str();
    return result;
}
double UserInputUI::convert_StringToDouble(string s) { /// Here we convert a string to a double using StringStream
    double result;
    stringstream convert(s);
    if ( !(convert >> result) ) {
        result = 0; /// if convert fails, result is 0
    }
    return result;
}
int UserInputUI::convert_StringToInteger(string s) { /// Here we convert a string to an integer using StringStream
    double result;
    stringstream convert(s);
    if ( !(convert >> result) ) {
        result = 0; /// if convert fails, result is 0
    }
    return result;
}
int UserInputUI::getAnswer_Integer(string question) { /// Here we ask the user a question and return the answer as an integer
    string answer;
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    return convert_StringToInteger(answer);
}
double UserInputUI::getAnswer_Double(string question) { /// Here we ask the user a question and return the answer as a double
    string answer;
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    return convert_StringToDouble(answer);
}
bool UserInputUI::getAnswer_Yes_Or_No(string question) { /// Here the user is asked the question repeatedly until he replies with yes or no
    string answer = getAnswer(question,"y","yes","n","no");
    if (answer == "y" || answer == "yes") {
        return true;
    }
    return false;
}

string UserInputUI::getAnswer(string question) { /// Here the user is asked the question once and we then return the answer
    string answer = "";
    cout << question << " ";
    cin >> ws;
    getline(cin,answer);
    return answer;
}

string UserInputUI::getAnswer(string question, string validAnswer) { /// Here the user is asked the question repeatedly until he replies with a validAnswer, we then return the answer
    string answer = "";
    while (answer != validAnswer) {
        cout << question << " ";
        cin >> ws;
        getline(cin,answer);
        answer = convert_StringToLowerCase(answer); /// We convert the answer to lowercase, sO WE doN'T hAvE to WOrrY aboUt CAPs LOcK
    }                                               /// Of course this means we need to have the validAnswers's in low-caps
    return answer;                                  /// I decided not to convert the validAnswers in this function though since I can just write them in low-caps to begin with
}
string UserInputUI::getAnswer(string q, string a1, string a2) { /// Two valid answers
    string a = "";
    while (a != a1 && a != a2) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
        a = convert_StringToLowerCase(a);
    }
    return a;
}
string UserInputUI::getAnswer(string q, string a1, string a2, string a3) { /// Three valid answers
    string a = "";
    while (a != a1 && a != a2 && a != a3) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
        a = convert_StringToLowerCase(a);
    }
    return a;
}
string UserInputUI::getAnswer(string q, string a1, string a2, string a3, string a4) { /// Four valid answers
    string a = "";
    while (a != a1 && a != a2 && a != a3 && a != a4) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
        a = convert_StringToLowerCase(a);
    }
    return a;
}
string UserInputUI::getAnswer(string q, string a1, string a2, string a3, string a4, string a5) { /// Five valid answers
    string a = "";
    while (a != a1 && a != a2 && a != a3 && a != a4 && a != a5) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
        a = convert_StringToLowerCase(a);
    }
    return a;
}
string UserInputUI::getAnswer(string q, string a1, string a2, string a3, string a4, string a5, string a6) { /// Six valid answers
    string a = "";
    while (a != a1 && a != a2 && a != a3 && a != a4 && a != a5 && a != a6) {
        cout << q << " ";
        cin >> ws;
        getline(cin,a);
        a = convert_StringToLowerCase(a);
    }
    return a;
}

