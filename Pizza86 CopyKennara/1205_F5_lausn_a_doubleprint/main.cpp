#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string a;

    ifstream fin;
    fin.open("number.txt");

    if (fin.is_open()) {
        while(fin >> a) {
            cout << a << endl;
        }
        fin.close();
    }





    /* Aðferð 3 (pre kaffi-pása í fyrirlestrinum

    string a;

    ifstream fin;
    fin.open("number.txt");

    if (fin.is_open()) {
        while(!fin.eof()) {
            getline(fin,a,','); // getline hefur parameter sem segir lestu
            cout << a << endl;  // þangað til 'c' (eitthvað char gildi, núna komma
        }
        fin.close();
    }

    /* Aðferð 2

    int a;

    ifstream fin;
    fin.open("number.txt");

    if (fin.is_open()) {
        while(fin >> a) {      // ATH! fin, ignores white-space and enter, need
            cout << a << endl; // Need to use getline if you actually want to read the text as-is
        }
        fin.close();            // This method may be usable for reading classes out of lines tho ...
    } */                        // Need to do some tests -> add to myFunctions / readFunctions


    /*         Aðferð 1 - "ógeðslegur kóði" - Bjöggi
    int a;

    ifstream fin;
    fin.open("number.txt");

    if (fin.is_open()) {
        while(!fin.eof()) {
            fin >> a;
            if (fin.eof()) {
                break;
            }
            cout << a;
        }
        fin.close();
    }
    */


    return 0;
}
