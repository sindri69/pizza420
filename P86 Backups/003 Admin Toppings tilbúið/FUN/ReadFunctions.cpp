#include "ReadFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ReadFunctions::ReadFunctions()
{
    //ctor
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

void ReadFunctions::read_fancy_type() {
    if (fileNotEmpty_type()) {
        int line = 1;
        ifstream fin ("type.txt");
        if (fin.is_open()) {
            for (int i = 0; i < (get_NumberOfLines_type() / 2); i++) {
                cout << get_Line_type(line) << " ";
                line++;
                cout << "($" << get_Line_type(line) << ")" << endl;
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
            for (int i = 0; i < (get_NumberOfLines_topping() / 2); i++) {
                cout << get_Line_topping(line) << " ";
                line++;
                cout << "($" << get_Line_topping(line) << ")" << endl;
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
                for (int i = 0; i < (get_NumberOfLines_type() / 2); i++) {
                    if (check_LineMatches_type(name,linenum)) {
                        cout << "That Type-name is already taken" << endl;
                        fin.close();
                        return false;
                    }
                    linenum = linenum + 2;
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
    if (fileNotEmpty_type()) {
        ifstream fin ("topping.txt");
        int linenum = 1;
        for (int i = 0; i < (get_NumberOfLines_topping() / 2); i++) {
            if (check_LineMatches_topping(name,linenum)) {
                cout << "That Topping-name is already taken" << endl;
                fin.close();
                return false;
            }
            linenum = linenum + 2;
        }
        fin.close();
    }
    return true;
}

