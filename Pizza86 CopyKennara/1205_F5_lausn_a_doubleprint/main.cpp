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





    /* A�fer� 3 (pre kaffi-p�sa � fyrirlestrinum

    string a;

    ifstream fin;
    fin.open("number.txt");

    if (fin.is_open()) {
        while(!fin.eof()) {
            getline(fin,a,','); // getline hefur parameter sem segir lestu
            cout << a << endl;  // �anga� til 'c' (eitthva� char gildi, n�na komma
        }
        fin.close();
    }

    /* A�fer� 2

    int a;

    ifstream fin;
    fin.open("number.txt");

    if (fin.is_open()) {
        while(fin >> a) {      // ATH! fin, ignores white-space and enter, need
            cout << a << endl; // Need to use getline if you actually want to read the text as-is
        }
        fin.close();            // This method may be usable for reading classes out of lines tho ...
    } */                        // Need to do some tests -> add to myFunctions / readFunctions


    /*         A�fer� 1 - "�ge�slegur k��i" - Bj�ggi
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
