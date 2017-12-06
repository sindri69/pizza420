#include <iostream>
#include <fstream>
#include "MainUI.h"

using namespace std;

class DataClass {

private:
    int i;
    double d;
    char str[16];
    char c;

    bool verbose;

public:

    DataClass() {
        i = 0;
        d = 0.0;
        str[0] = '\0' ;
        c = ' ';

        verbose = true;
    }

    void setVerbose(bool v) {
        verbose = v;
    }

    void fixStrings() {
        str[15] = '\0';
    }

    friend istream& operator >> (istream& in, DataClass& data) {

        if (data.verbose) {
            cout << "Enter integer: ";
        }
        in >> data.i;

        if (data.verbose) {
            cout << "Enter double: ";
        }
        in >> data.d;

        if (data.verbose) {
            cout << "Enter string: ";
        }
        in >> data.str;

        if (data.verbose) {
            cout << "Enter char: ";
        }
        in >> data.c;

        return in;
    }

    friend ostream& operator << (ostream& out, const DataClass& data) {

        if (data.verbose) {
            out << "Integer: ";
        }
        out << data.i << endl;

        if (data.verbose) {
            out << "Double : ";
        }
        out << data.d << endl;

        if (data.verbose) {
            out << "String : ";
        }
        out << data.str << endl;

        if (data.verbose) {
            out << "Char   : ";
        }
        out << data.c << endl;

        return out;
    }

};

int main()
{
    MainUI mainui;
    mainui.startUI();

    return 0;
}
