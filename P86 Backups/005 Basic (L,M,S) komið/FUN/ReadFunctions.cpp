#include "ReadFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int numberofvaluesintypesandtoppings = 4;

ReadFunctions::ReadFunctions()
{
    //ctor
}

void ReadFunctions::read_raw_basic() {
    if (fileNotEmpty_basic()) {
        string line;
        ifstream fin ("basic.txt");
        if (fin.is_open()) {
            while (getline(fin,line)) {
                cout << line << endl;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ReadFunctions::read_raw_pizza() {
    if (fileNotEmpty_pizza()) {
        string line;
        ifstream fin ("pizza.txt");
        if (fin.is_open()) {
            while (getline(fin,line)) {
                cout << line << endl;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ReadFunctions::read_raw_type() {
    if (fileNotEmpty_type()) {
        string line;
        ifstream fin ("type.txt");
        if (fin.is_open()) {
            while (getline(fin,line)) {
                cout << line << endl;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ReadFunctions::read_raw_topping() {
    if (fileNotEmpty_topping()) {
        string line;
        ifstream fin ("topping.txt");
        if (fin.is_open()) {
            while (getline(fin,line)) {
                cout << line << endl;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}

void ReadFunctions::read_fancy_basic() {
    if (fileNotEmpty_basic()) {
        cout << "(L = $" << get_Line_basic(1) << ") ";
        cout << "(M = $" << get_Line_basic(2) << ") ";
        cout << "(S = $" << get_Line_basic(3) << ")" << endl;
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ReadFunctions::read_fancy_pizza() {
    if (fileNotEmpty_pizza()) {
        int line = 1;
        for (int i = 0; i < (get_NumberOfLines_pizza() / 6); i++) {
            string psize = get_Line_pizza(line);
            line++;
            string ptype = get_Line_pizza(line);
            line++;
            string ptopping = get_Line_pizza(line);
            line++;
            string pprice = get_Line_pizza(line);
            line++;
            string ppayedfor = get_Line_pizza(line);
            line++;
            string pstatus = get_Line_pizza(line);
            line++;

            cout << psize << " " << ptype << " ";
            if (ptype == "Custom") {
                cout << "Pizza with " << ptopping << " ";
            }
            cout << "($" << pprice << ") ";
            if (ppayedfor == "1") {
                cout << "(Already payed for) ";
            }
            else {
                cout << "(Not payed for) ";
            }
            if (pstatus == "1") {
                cout << "(Pizza not made yet)" << endl;
            }
            if (pstatus == "2") {
                cout << "(Pizza being made)" << endl;
            }
            if (pstatus == "3") {
                cout << "(Pizza is ready)" << endl;
            }
            if (pstatus == "4") {
                cout << "(Pizza has been delivered)" << endl;
            }
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ReadFunctions::read_fancy_type() {
    if (fileNotEmpty_type()) {
        int line = 1;
        ifstream fin ("type.txt");
        if (fin.is_open()) {
            for (int i = 0; i < (get_NumberOfLines_type() / numberofvaluesintypesandtoppings); i++) {
                cout << get_Line_type(line) << " ";
                line++;
                cout << "(L = $" << get_Line_type(line) << ") ";
                line++;
                cout << "(M = $" << get_Line_type(line) << ") ";
                line++;
                cout << "(S = $" << get_Line_type(line) << ")" << endl;
                line++;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}
void ReadFunctions::read_fancy_topping() {
    if (fileNotEmpty_topping()) {
        int line = 1;
        ifstream fin ("topping.txt");
        if (fin.is_open()) {
            for (int i = 0; i < (get_NumberOfLines_topping() / numberofvaluesintypesandtoppings); i++) {
                cout << get_Line_topping(line) << " ";
                line++;
                cout << "(L = $" << get_Line_topping(line) << ") ";
                line++;
                cout << "(M = $" << get_Line_topping(line) << ") ";
                line++;
                cout << "(S = $" << get_Line_topping(line) << ")" << endl;
                line++;
            }
            fin.close();
        }
        else {
            cout << "File not open" << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}

void ReadFunctions::delete_basic() {
    ofstream fout;
    fout.open ("basic.txt");
    fout.close();
}
void ReadFunctions::delete_pizza() {
    ofstream fout;
    fout.open ("pizza.txt");
    fout.close();
}
void ReadFunctions::delete_type() {
    ofstream fout;
    fout.open ("type.txt");
    fout.close();
}
void ReadFunctions::delete_topping() {
    ofstream fout;
    fout.open ("topping.txt");
    fout.close();
}

string ReadFunctions::get_Line_basic(int linenumber) {
    ifstream fin ("basic.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
string ReadFunctions::get_Line_pizza(int linenumber) {
    ifstream fin ("pizza.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
string ReadFunctions::get_Line_type(int linenumber) {
    ifstream fin ("type.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}
string ReadFunctions::get_Line_topping(int linenumber) {
    ifstream fin ("topping.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}

int ReadFunctions::get_NumberOfLines_basic() {
    int numberoflines = 0;
    string line;
    ifstream fin ("basic.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
int ReadFunctions::get_NumberOfLines_pizza() {
    int numberoflines = 0;
    string line;
    ifstream fin ("pizza.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
int ReadFunctions::get_NumberOfLines_type() {
    int numberoflines = 0;
    string line;
    ifstream fin ("type.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}
int ReadFunctions::get_NumberOfLines_topping() {
    int numberoflines = 0;
    string line;
    ifstream fin ("topping.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}

bool ReadFunctions::fileNotEmpty_basic() {
    if (get_NumberOfLines_basic() == 0) {
        return false;
    }
    return true;
}
bool ReadFunctions::fileNotEmpty_pizza() {
    if (get_NumberOfLines_pizza() == 0) {
        return false;
    }
    return true;
}
bool ReadFunctions::fileNotEmpty_type() {
    if (get_NumberOfLines_type() == 0) {
        return false;
    }
    return true;
}
bool ReadFunctions::fileNotEmpty_topping() {
    if (get_NumberOfLines_topping() == 0) {
        return false;
    }
    return true;
}

bool ReadFunctions::check_LineMatches_basic(string line, int linenumber) {
    if (get_Line_basic(linenumber) == line) {
        return true;
    }
    return false;
}
bool ReadFunctions::check_LineMatches_pizza(string line, int linenumber) {
    if (get_Line_pizza(linenumber) == line) {
        return true;
    }
    return false;
}
bool ReadFunctions::check_LineMatches_type(string line, int linenumber) {
    if (get_Line_type(linenumber) == line) {
        return true;
    }
    return false;
}
bool ReadFunctions::check_LineMatches_topping(string line, int linenumber) {
    if (get_Line_topping(linenumber) == line) {
        return true;
    }
    return false;
}

bool ReadFunctions::check_NameIsAvailable_type(string name) {
    if (name != "Basic") {
        if (name != "Custom") {
            if (fileNotEmpty_type()) {
                ifstream fin ("type.txt");
                int linenum = 1;
                for (int i = 0; i < (get_NumberOfLines_type() / numberofvaluesintypesandtoppings); i++) {
                    if (check_LineMatches_type(name,linenum)) {
                        cout << "That Type-name is already taken" << endl;
                        fin.close();
                        return false;
                    }
                    linenum = linenum + numberofvaluesintypesandtoppings;
                }
                fin.close();
            }
            return true;
        }
        else {
            cout << "The Type-name \"Custom\" is reserved" << endl;
            return false;
        }
    }
    else {
        cout << "The Type-name \"Basic\" is reserved" << endl;
        return false;
    }
}
bool ReadFunctions::check_NameIsAvailable_topping(string name) {
    if (fileNotEmpty_topping()) {
        ifstream fin ("topping.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines_topping() / numberofvaluesintypesandtoppings); i++) {
            if (check_LineMatches_topping(name,linenum)) {
                cout << "That Topping-name is already taken" << endl;
                fin.close();
                return false;
            }
            linenum = linenum + numberofvaluesintypesandtoppings;
        }
        fin.close();
    }
    return true;
}

bool ReadFunctions::check_TypeExists_type(string name) {
    if (fileNotEmpty_type()) {
        ifstream fin ("type.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines_type() / numberofvaluesintypesandtoppings); i++) {
            if (check_LineMatches_type(name,linenum)) {
                fin.close();
                return true;
            }
            linenum = linenum + numberofvaluesintypesandtoppings;
        }
        fin.close();
    }
    return false;
}
bool ReadFunctions::check_ToppingExists_topping(string name) {
    if (fileNotEmpty_topping()) {
        ifstream fin ("topping.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines_topping() / numberofvaluesintypesandtoppings); i++) {
            if (check_LineMatches_topping(name,linenum)) {
                fin.close();
                return true;
            }
            linenum = linenum + numberofvaluesintypesandtoppings;
        }
        fin.close();
    }
    return false;
}

