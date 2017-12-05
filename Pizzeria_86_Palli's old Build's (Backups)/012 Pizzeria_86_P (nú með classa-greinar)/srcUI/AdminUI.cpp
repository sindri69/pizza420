#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "AdminUI.h"
#include "AdminPizzaUI.h"
#include "AdminTypesUI.h"
#include "AdminToppingsUI.h"
#include "AdminDrinksUI.h"
#include "AdminExtrasUI.h"
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
        cout << "1: Go to PizzaList" << endl;
        cout << "2: Go to TypesList" << endl;
        cout << "3: Go to ToppingsList" << endl;
        cout << "4: Go to DrinksList" << endl;
        cout << "5: Go to ExtrasList" << endl;
        cout << "6: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') {
            AdminPizzaUI adminpizzaui;
            adminpizzaui.start_adminPizzaUI();
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
