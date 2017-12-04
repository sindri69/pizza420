#include "AdminPizzaListUI.h"
#include "readFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminPizzaListUI::AdminPizzaListUI()
{
    //ctor
}

AdminPizzaListUI::~AdminPizzaListUI()
{
    //dtor
}

void AdminPizzaListUI::start_adminPizzaListUI() {

    char selection = '0';
    while (selection != 'q') { /* This loop won't end until user selects "Return to Administrator" */

        cout << "Pizzeria_86_Programma (Administrator / PizzaList) " << endl;
        cout << "1: Read PizzaList (raw)" << endl;
        cout << "2: Read PizzaList (fancy)" << endl;
        cout << "3: Purge PizzaList" << endl;
        cout << "4: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') { /* This prints all the lines in PizzaList without any alterations */
            readFunctions fun;
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
            readFunctions fun;
            fun.read_PizzaListFancy();
        }
        else if (selection == '3') {
            string choice = ""; /* The only legit user-input are variations of yes and no */
            while (choice != "y" && choice != "Y" && choice != "yes" && choice != "Yes" && choice != "YES" && choice != "n" && choice != "N" && choice != "no" && choice != "No" && choice != "NO") {
                cout << "Are you sure you wish to delete all the content in PizzaList? ";
                cin >> choice;
            }
            if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES") { /* If yes, purge */
                ofstream f; /* Here we open "PizzaList.txt" without ios::app, this does not delete the file but it does remove all content inside it */
                f.open("PizzaList.txt");
                f.close();
                cout << "PizzaList has been purged" << endl;
                cout << endl;
            }
            else { /* If no, no purge */
                cout << "Purge Aborted" << endl;
                cout << endl;
            }
        }
        else if (selection == '4') { /* Return to AdministratorUI */
            selection = 'q';
        }
    }
}
