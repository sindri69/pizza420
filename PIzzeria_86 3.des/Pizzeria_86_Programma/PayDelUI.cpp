#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "PayDelUI.h"
using namespace std;



PayDelUI::PayDelUI()
{
    //ctor
}

PayDelUI::~PayDelUI()
{
    //dtor
}

void PayDelUI::start_paydelUI() {

    /* Eins og er gerir þetta UI ekkert, getur bara hoppað til baka í mainUI */

    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Payments & Delivery)" << endl;
        cout << "1: Nothing" << endl;
        cout << "2: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') {
            cout << "Nada" << endl;
        }
        else if (selection == '2') {
            selection = 'q';
        }
    }
}
