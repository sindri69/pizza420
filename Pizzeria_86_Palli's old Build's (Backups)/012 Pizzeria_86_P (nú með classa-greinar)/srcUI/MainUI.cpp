#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "AdminUI.h"
#include "OrderUI.h"
#include "BakingUI.h"
#include "PayDeliverUI.h"
using namespace std;

MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::start_mainUI() {

    /* Basic Loop */
    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma" << endl;
        cout << "1: Administrator" << endl;
        cout << "2: Order" << endl;
        cout << "3: Baking" << endl;
        cout << "4: Pay/Deliver" << endl;
        cout << "5: Exit Program" << endl;

        cin >> selection;

        if (selection == '1') {
            AdminUI adminui;
            adminui.start_adminUI();
        }
        else if (selection == '2') {
            OrderUI orderui;
            orderui.start_orderUI();
        }
        else if (selection == '3') {
            BakingUI bakingui;
            bakingui.start_bakingUI();
        }
        else if (selection == '4') {
            PayDeliverUI paydeliverui;
            paydeliverui.start_paydeliverUI();
        }
        else if (selection == '5') {
            cout << "Arrivederci" << endl;
            selection = 'q';
        }
    }
}
