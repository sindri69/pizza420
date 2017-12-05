#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "AdminUI.h"
#include "AdminPizzaListUI.h"
#include "AdminTypesUI.h"
#include "AdminToppingsUI.h"
#include "AdminDrinksUI.h"
#include "adminExtrasUI.h"
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

    /* Eins og er gerir þetta UI ekkert, getur bara hoppað til baka í mainUI */

    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Administrator)" << endl;
        cout << "1: Go to PizzaList" << endl;
        cout << "2: Go to Pizza-Types" << endl;
        cout << "3: Go to Pizza-Toppings" << endl;
        cout << "4: Go to Pizza-Drinks" << endl;
        cout << "5: Go to Pizza-Extras" << endl;
        cout << "6: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') {
            AdminPizzaListUI adminpizzalistui;
            adminpizzalistui.start_adminPizzaListUI();
        }
        else if (selection == '2') {
            AdminTypesUI admintypesui;
            admintypesui.start_adminTypesUI();
        }
        else if (selection == '3') {
            AdminToppingsUI admintoppingsui;
            admintoppingsui.start_adminToppingsUI();
        }
        else if (selection == '4') {
            AdminDrinksUI admindrinksui;
            admindrinksui.start_adminDrinksUI();
        }
        else if (selection == '5') {
            AdminExtrasUI adminextrasui;
            adminextrasui.start_adminExtrasUI();
        }
        else if (selection == '6') {
            selection = 'q';
        }
    }
}
