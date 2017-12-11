#include "ReadFunctions.h"
#include "MyFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int NUMBEROFVALUESINEMPLOYEE = 5;

ReadFunctions::ReadFunctions()
{
    //ctor
}

void ReadFunctions::read_raw_employee() {
    if (fileNotEmpty_employee()) {
        string line;
        ifstream fin ("employee.txt");
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

void ReadFunctions::read_fancy_employee() {
    if (fileNotEmpty_employee()) {
        int line = 1;
        for (int i = 0; i < (get_NumberOfLines_employee() / NUMBEROFVALUESINEMPLOYEE); i++) {
            string name = get_Line_employee(line);
            line++;
            string ssn = get_Line_employee(line);
            line++;
            string salary = get_Line_employee(line);
            line++;
            string month = get_Line_employee(line);
            line++;
            string year = get_Line_employee(line);
            line++;

            cout << "Name: " << name << " SSN: " << ssn;
            cout << "Salary: " << salary << " Month: ";

            if (month == "1") {
                cout << "January ";
            }
            else if (month == "2") {
                cout << "February ";
            }
            else if (month == "3") {
                cout << "March ";
            }
            else if (month == "4") {
                cout << "April ";
            }
            else if (month == "5") {
                cout << "May ";
            }
            else if (month == "6") {
                cout << "June ";
            }
            else if (month == "7") {
                cout << "July ";
            }
            else if (month == "8") {
                cout << "August ";
            }
            else if (month == "9") {
                cout << "September ";
            }
            else if (month == "10") {
                cout << "October ";
            }
            else if (month == "11") {
                cout << "November ";
            }
            else if (month == "12") {
                cout << "December ";
            }
            else {
                cout << "Error, month does not exist" << endl;
            }
            cout << year << endl << endl;
        }
    }
    else {
        cout << "File is empty" << endl;
    }
}

void ReadFunctions::delete_employee() {
    ofstream fout;
    fout.open ("employee.txt");
    fout.close();
}

string ReadFunctions::get_Line_employee(int linenumber) {
    ifstream fin ("employee.txt");
    string s = "";
    if (fin.is_open()) {
        for (int i = 1; i <= linenumber; i++) {
            getline(fin,s);
        }
        fin.close();
    }
    return s;
}


int ReadFunctions::get_NumberOfLines_employee() {
    int numberoflines = 0;
    string line;
    ifstream fin ("employee.txt");
    if (fin.is_open()) {
        while (getline(fin,line)) {
            ++numberoflines;
        }
        fin.close();
    }
    return numberoflines;
}


bool ReadFunctions::fileNotEmpty_employee() {
    if (get_NumberOfLines_employee() == 0) {
        return false;
    }
    return true;
}

bool ReadFunctions::check_LineMatches_employee(string line, int linenumber) {
    MyFunctions myfun;
    if (myfun.convert_StringToLowerCase(get_Line_employee(linenumber)) == myfun.convert_StringToLowerCase(line)) {
        return true;
    }
    return false;
}

