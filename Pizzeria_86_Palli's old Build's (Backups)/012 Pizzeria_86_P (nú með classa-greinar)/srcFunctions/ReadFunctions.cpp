#include "ReadFunctions.h"
#include "Pizza.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int numberOfValuesInPizzaClass = 8; /* Make sure to update this value if need be */

ReadFunctions::ReadFunctions()
{
    //ctor
}

ReadFunctions::~ReadFunctions()
{
    //dtor
}

bool ReadFunctions::fileExists_PizzaList() { /* http://www.cplusplus.com/doc/tutorial/files/ */
    ifstream f ("PizzaList.txt");
    bool doesFileExist = f.good(); /* f.good() is a "generic" state flag, returns false in the same cases that bad(), fail() and eof() would return true */
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
bool ReadFunctions::fileExists_TypesList() {
    ifstream f ("TypesList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
bool ReadFunctions::fileExists_ToppingsList() {
    ifstream f ("ToppingsList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
bool ReadFunctions::fileExists_DrinksList() {
    ifstream f ("DrinksList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
bool ReadFunctions::fileExists_ExtrasList() {
    ifstream f ("ExtrasList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}

bool ReadFunctions::fileExists_AndNotEmpty_PizzaList() {
    ReadFunctions fun;
    if (fun.fileExists_PizzaList() && fun.get_NumberOfLines_PizzaList() != 0) {
        return true;
    }
    return false;
}
bool ReadFunctions::fileExists_AndNotEmpty_TypesList() {
    ReadFunctions fun;
    if (fun.fileExists_TypesList() && fun.get_NumberOfLines_TypesList() != 0) {
        return true;
    }
    return false;
}
bool ReadFunctions::fileExists_AndNotEmpty_ToppingsList() {
    ReadFunctions fun;
    if (fun.fileExists_ToppingsList() && fun.get_NumberOfLines_ToppingsList() != 0) {
        return true;
    }
    return false;
}
bool ReadFunctions::fileExists_AndNotEmpty_DrinksList() {
    ReadFunctions fun;
    if (fun.fileExists_DrinksList() && fun.get_NumberOfLines_DrinksList() != 0) {
        return true;
    }
    return false;
}
bool ReadFunctions::fileExists_AndNotEmpty_ExtrasList() {
    ReadFunctions fun;
    if (fun.fileExists_ExtrasList() && fun.get_NumberOfLines_ExtrasList() != 0) {
        return true;
    }
    return false;
}

bool ReadFunctions::nameSake_PizzaList(string line) {
    ReadFunctions fun;
    if (fun.fileExists_AndNotEmpty_PizzaList()) {
        int numoflines = fun.get_NumberOfLines_PizzaList(); /* Count number of lines in the text file */
        for (int i=0; i < numoflines; i++) { /* loop as often as the amount of lines in the text file */
            if (line == fun.get_Line_PizzaList(i)) {
                return true; /* If any of the lines in the text file matches userInput, return true */
            }
        }
    }
    return false; /* If no lines match, return false */
}
bool ReadFunctions::nameSake_TypesList(string line) {
    ReadFunctions fun;
    if (fun.fileExists_AndNotEmpty_TypesList()) {
        int numoflines = fun.get_NumberOfLines_TypesList();
        for (int i=0; i < numoflines; i++) {
            if (line == fun.get_Line_TypesList(i)) {
                return true;
            }
        }
    }
    return false;
}
bool ReadFunctions::nameSake_ToppingsList(string line) {
    ReadFunctions fun;
    if (fun.fileExists_AndNotEmpty_ToppingsList()) {
        int numoflines = fun.get_NumberOfLines_ToppingsList();
        for (int i=0; i < numoflines; i++) {
            if (line == fun.get_Line_ToppingsList(i)) {
                return true;
            }
        }
    }
    return false;
}
bool ReadFunctions::nameSake_DrinksList(string line) {
    ReadFunctions fun;
    if (fun.fileExists_AndNotEmpty_DrinksList()) {
        int numoflines = fun.get_NumberOfLines_DrinksList();
        for (int i=0; i < numoflines; i++) {
            if (line == fun.get_Line_DrinksList(i)) {
                return true;
            }
        }
    }
    return false;
}
bool ReadFunctions::nameSake_ExtrasList(string line) {
    ReadFunctions fun;
    if (fun.fileExists_AndNotEmpty_ExtrasList()) {
        int numoflines = fun.get_NumberOfLines_ExtrasList();
        for (int i=0; i < numoflines; i++) {
            if (line == fun.get_Line_ExtrasList(i)) {
                return true;
            }
        }
    }
    return false;
}

bool ReadFunctions::lineMatches_PizzaList(string line, int linenum) {
    ReadFunctions fun;
    if (fun.get_Line_PizzaList(linenum) == line) { /* Here I'm using get_Line to see if the string matches the line in the file */
        return true;
    }
    return false;
}
bool ReadFunctions::lineMatches_TypesList(string line, int linenum) {
    ReadFunctions fun;
    if (fun.get_Line_TypesList(linenum) == line) {
        return true;
    }
    return false;
}
bool ReadFunctions::lineMatches_ToppingsList(string line, int linenum) {
    ReadFunctions fun;
    if (fun.get_Line_ToppingsList(linenum) == line) {
        return true;
    }
    return false;
}
bool ReadFunctions::lineMatches_DrinksList(string line, int linenum) {
    ReadFunctions fun;
    if (fun.get_Line_DrinksList(linenum) == line) {
        return true;
    }
    return false;
}
bool ReadFunctions::lineMatches_ExtrasList(string line, int linenum) {
    ReadFunctions fun;
    if (fun.get_Line_ExtrasList(linenum) == line) {
        return true;
    }
    return false;
}

int ReadFunctions::get_NumberOfLines_PizzaList() {
    int number_of_lines = 0;
    string line;
    ifstream f ("PizzaList.txt");

    if (f.is_open()) {
        while (getline(f,line)) { /* Here we count the number of lines in the file */
            ++number_of_lines;
        }
        f.close();
    }
    return number_of_lines;
}
int ReadFunctions::get_NumberOfLines_TypesList() {
    int number_of_lines = 0;
    string line;
    ifstream f ("TypesList.txt");

    if (f.is_open()) {
        while (getline(f,line)) {
            ++number_of_lines;
        }
        f.close();
    }
    return number_of_lines;
}
int ReadFunctions::get_NumberOfLines_ToppingsList() {
    int number_of_lines = 0;
    string line;
    ifstream f ("ToppingsList.txt");

    if (f.is_open()) {
        while (getline(f,line)) {
            ++number_of_lines;
        }
        f.close();
    }
    return number_of_lines;
}
int ReadFunctions::get_NumberOfLines_DrinksList() {
    int number_of_lines = 0;
    string line;
    ifstream f ("DrinksList.txt");

    if (f.is_open()) {
        while (getline(f,line)) {
            ++number_of_lines;
        }
        f.close();
    }
    return number_of_lines;
}
int ReadFunctions::get_NumberOfLines_ExtrasList() {
    int number_of_lines = 0;
    string line;
    ifstream f ("ExtrasList.txt");

    if (f.is_open()) {
        while (getline(f,line)) {
            ++number_of_lines;
        }
        f.close();
    }
    return number_of_lines;
}

string ReadFunctions::get_Line_PizzaList(int linenum) {
    ifstream f ("PizzaList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= linenum; i++) { /* This method keeps "getting" the line from the file until the current line-number is correct, it then return the "current" line-number */
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
string ReadFunctions::get_Line_TypesList(int linenum) {
    ifstream f ("TypesList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= linenum; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
string ReadFunctions::get_Line_ToppingsList(int linenum) {
    ifstream f ("ToppingsList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= linenum; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
string ReadFunctions::get_Line_DrinksList(int linenum) {
    ifstream f ("DrinksList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= linenum; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
string ReadFunctions::get_Line_ExtrasList(int linenum) {
    ifstream f ("ExtrasList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= linenum; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}

void ReadFunctions::read_PizzaList() {
    string line;
    ifstream f ("PizzaList.txt");
    if (f.is_open()) {
        while (getline(f,line)) { /* Here we keep printing out the lines in the file until the file ends */
            cout << line << endl;
        }
        f.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}
void ReadFunctions::read_TypesList() {
    string line;
    ifstream f ("TypesList.txt");
    if (f.is_open()) {
        while (getline(f,line)) {
            cout << line << endl;
        }
        f.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}
void ReadFunctions::read_ToppingsList() {
    string line;
    ifstream f ("ToppingsList.txt");
    if (f.is_open()) {
        while (getline(f,line)) {
            cout << line << endl;
        }
        f.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}
void ReadFunctions::read_DrinksList() {
    string line;
    ifstream f ("DrinksList.txt");
    if (f.is_open()) {
        while (getline(f,line)) {
            cout << line << endl;
        }
        f.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}
void ReadFunctions::read_ExtrasList() {
    string line;
    ifstream f ("ExtrasList.txt");
    if (f.is_open()) {
        while (getline(f,line)) {
            cout << line << endl;
        }
        f.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

void ReadFunctions::read_PizzaListFancy() {
    ReadFunctions fun;
    if (fun.fileExists_PizzaList()) { /* If the PizzaList exists, then we can continue */
        if (fun.get_NumberOfLines_PizzaList() != 0) { /* If the PizzaList is not empty then we can continue */
            Pizza pizza;
            ifstream fin;
            fin.open("PizzaList.txt");
            int linecount = 1;
            for (int i = 0; i < (fun.get_NumberOfLines_PizzaList() / numberOfValuesInPizzaClass); i++) { /* Here we count the number of lines in the file and divide it with the number of values in Pizza Class to know how many Pizza's there are listed */
                cout << "Size (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Type (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Toppings (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Drinks (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Extras (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Price (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Payedfor (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ") Status (" << fun.get_Line_PizzaList(linecount);
                linecount++;
                cout << ")" << endl;
            }
            fin.close();
        }
        else {
            cout << "The PizzaList file is currently empty" << endl; /* If the PizzaList is empty then we can't continue */
        }
    }
    else {
        cout << "The PizzaList file does not exist" << endl; /* If the PizzaList does not exist then we can't continue */
    }
}
