#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "BakingUI.h"
using namespace std;

BakingUI::BakingUI()
{
    //ctor
}

BakingUI::~BakingUI()
{
    //dtor
}

void BakingUI::start_bakingUI() {

    /* Eins og er gerir þetta UI ekkert, getur bara hoppað til baka í mainUI */

    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Baking)" << endl;
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
