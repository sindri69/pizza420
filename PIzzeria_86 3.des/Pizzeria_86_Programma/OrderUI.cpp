#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "OrderUI.h"
#include "Pizza.h"
#include "myFunctions.h"
#include "readFunctions.h"
using namespace std;

const int numberOfValuesInPizzaClass = 8; /* Make sure to update this value if need be */

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
        cout << "1: Add Order" << endl;
        cout << "2: See list of all Orders ( This does not work )" << endl;
        cout << "3: See list of all Orders ( This does work, hurray ! )" << endl;
        cout << "4: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') { /* Here we are adding to the PizzaList */
            int choice;

            cout << "How many pizzas do you wish to add to the list? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Pizza pizza;                             /* Here we declare the Pizza Class */
                pizza.setVerbose(true);                  /* Verbose, cause we want extra-text */
                cin >> pizza;                            /* Here we take in all of the class (all of the private values, except verbose) */
                ofstream fout;                           /* ofstream is used to add to text-files */
                fout.open("PizzaList.txt", ios::app);    /* Here we open PizzaList.txt, the "ios:app means that it will add the list but not overwrite it */
                pizza.setVerbose(false);                 /* Verbose, we don't want extra-text into the file */
                fout << pizza;                           /* Here we add the Pizza Class to the file (all of the private values, except verbose) */
                fout.close();                            /* Finally we close the text-file so we can access it later from other classes */
            }
        }
        else if (selection == '2') { /* Note: This does not work as intended, if it can't be fixed it will likely be removed, since we have an alternative method that does work */

            readFunctions fun;
            if (fun.fileExists_PizzaList()) { /* If the PizzaList exists, then we can continue */
                if (fun.get_NumberOfLines_PizzaList() != 0) { /* If the PizzaList is not empty then we can continue */
                    Pizza pizza;
                    ifstream fin;
                    fin.open("PizzaList.txt");
                    for (int i = 0; i < (fun.get_NumberOfLines_PizzaList() / numberOfValuesInPizzaClass); i++) { /* Here we count the number of lines in the file and divide it with the number of values in Pizza Class to know how many Pizza's there are listed */
                        pizza.setVerbose(false); /* We don't want extra-text when we read from the file */
                        fin >> pizza;
                        pizza.setVerbose(true);  /* We want extra-text when we print to the screen */
                        cout << pizza;
                    }
                    fin.close();
                }
                else {
                    cout << "The PizzaList file is currently empty" << endl; /* If the PizzaList is empty then we can't continue */
                }
            }
            else {
                cout << "The PizzaList file does not exist" << endl; /* If the PizzaList does not exist then we can't continue */
            }
        }
        else if (selection == '3') { /* This method actually works, awesome */
            readFunctions fun;
            fun.read_PizzaListFancy();
        }
        else if (selection == '4') { /* This ends the loop, sending us back to mainUI */
            selection = 'q';
        }
    }
}
