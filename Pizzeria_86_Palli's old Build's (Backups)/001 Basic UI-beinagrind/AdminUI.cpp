#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "AdminUI.h"
using namespace std;

AdminUI::AdminUI()
{
    //ctor
}

AdminUI::~AdminUI()
{
    //dtor
}

void AdminUI::start_adminUI() {

    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Administrator)" << endl;
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
