#include "readFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

readFunctions::readFunctions()
{
    //ctor
}

readFunctions::~readFunctions()
{
    //dtor
}

bool readFunctions::fileExists_PizzaList() { /* If the file exists, returns true */
    ifstream f ("PizzaList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
int readFunctions::get_NumberOfLines_PizzaList() { /* Counts the number of lines in the file */
    int number_of_lines = 0;
    string line;
    ifstream f ("PizzaList.txt");

    if (f.is_open()) {
        while (getline(f,line)) {
            ++number_of_lines;
        }
        f.close();
    }
    return number_of_lines;
}
string readFunctions::get_Line_PizzaList(int line) { /* Returns line number "line" as a string */
    ifstream f ("PizzaList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= line; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
void readFunctions::read_PizzaList() { /* Reads all the lines in the file */
    string line;
    ifstream f ("PizzaList.txt");
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

bool readFunctions::fileExists_TypesList() { /* If the file exists, returns true */
    ifstream f ("TypesList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
int readFunctions::get_NumberOfLines_TypesList() { /* Counts the number of lines in the file */
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
string readFunctions::get_Line_TypesList(int line) { /* Returns line number "line" as a string */
    ifstream f ("TypesList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= line; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
void readFunctions::read_TypesList() { /* Reads all the lines in the file */
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

bool readFunctions::fileExists_ToppingsList() { /* If the file exists, returns true */
    ifstream f ("ToppingsList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
int readFunctions::get_NumberOfLines_ToppingsList() { /* Counts the number of lines in the file */
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
string readFunctions::get_Line_ToppingsList(int line) { /* Returns line number "line" as a string */
    ifstream f ("ToppingsList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= line; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
void readFunctions::read_ToppingsList() { /* Reads all the lines in the file */
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

bool readFunctions::fileExists_DrinksList() { /* If the file exists, returns true */
    ifstream f ("DrinksList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
int readFunctions::get_NumberOfLines_DrinksList() { /* Counts the number of lines in the file */
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
string readFunctions::get_Line_DrinksList(int line) { /* Returns line number "line" as a string */
    ifstream f ("DrinksList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= line; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
void readFunctions::read_DrinksList() { /* Reads all the lines in the file */
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

bool readFunctions::fileExists_ExtrasList() { /* If the file exists, returns true */
    ifstream f ("ExtrasList.txt");
    bool doesFileExist = f.good();
    if (f.is_open()) {
        f.close();
    }
    return doesFileExist;
}
int readFunctions::get_NumberOfLines_ExtrasList() { /* Counts the number of lines in the file */
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
string readFunctions::get_Line_ExtrasList(int line) { /* Returns line number "line" as a string */
    ifstream f ("ExtrasList.txt");
    string s = "";

    if (f.is_open()) {
        for (int i = 1; i <= line; i++) {
            getline(f,s);
        }
        f.close();
        return s;
    }
    else {
        return s;
    }
}
void readFunctions::read_ExtrasList() { /* Reads all the lines in the file */
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
