#include "AdminPizzaUI.h"
#include "ReadFunctions.h"
#include "MyFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminPizzaUI::AdminPizzaUI()
{
    //ctor
}

AdminPizzaUI::~AdminPizzaUI()
{
    //dtor
}

void AdminPizzaUI::start_adminPizzaUI() {

    ReadFunctions fun; /* Functions that read from text-files */
    MyFunctions myfun; /* Other Functions */

    char selection = '0';
    while (selection != 'q') { /* This loop won't end until user selects "Return to Administrator" */

        cout << "Pizzeria_86_Programma (Administrator / PizzaList) " << endl;
        cout << "1: Read PizzaList (raw)" << endl;
        cout << "2: Read PizzaList (fancy)" << endl;
        cout << "3: Purge PizzaList" << endl;
        cout << "4: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') { /* This prints all the lines in PizzaList without any alterations */
            if (fun.fileExists_PizzaList() && fun.get_NumberOfLines_PizzaList() != 0) {
                fun.read_PizzaList();
            }
            else if (fun.fileExists_PizzaList() && fun.get_NumberOfLines_PizzaList() == 0) {
                cout << "PizzaList is empty" << endl;
            }
            else {
                cout << "PizzaList does not exist" << endl;
            }
        }
        else if (selection == '2') { /* Later this will print the orders in a neat and human friendly way */
            fun.read_PizzaListFancy();
        }
        else if (selection == '3') {
            if (myfun.getAnswer_Yes_Or_No("Are you sure you wish to delete all the content in PizzaList?")) {
                ofstream f;
                f.open("PizzaList.txt"); /* Here we open "PizzaList.txt" without ios::app, this does not delete the file but it does remove all content inside it */
                f.close();
                cout << "PizzaList has been purged" << endl;
            }
            else {
                cout << "Purge Aborted" << endl;
            }
        }
        else if (selection == '4') { /* Return to AdministratorUI */
            selection = 'q';
        }
    }
}
