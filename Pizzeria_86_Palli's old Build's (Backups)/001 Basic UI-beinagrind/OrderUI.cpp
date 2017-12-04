#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "OrderUI.h"
using namespace std;

OrderUI::OrderUI()
{
    //ctor
}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::start_orderUI() {

    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Orders)" << endl;
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
