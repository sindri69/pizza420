#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "PayDeliverUI.h"
using namespace std;


PayDeliverUI::PayDeliverUI()
{
    //ctor
}

PayDeliverUI::~PayDeliverUI()
{
    //dtor
}

void PayDeliverUI::start_paydeliverUI() {

    /* Eins og er gerir �etta UI ekkert, getur bara hoppa� til baka � mainUI */

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
