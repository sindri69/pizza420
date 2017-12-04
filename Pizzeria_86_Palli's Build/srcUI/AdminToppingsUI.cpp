#include "AdminToppingsUI.h"
#include "Toppings.h"
#include "ReadFunctions.h"
#include "MyFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminToppingsUI::AdminToppingsUI()
{
    //ctor
}

AdminToppingsUI::~AdminToppingsUI()
{
    //dtor
}

void AdminToppingsUI::start_adminToppingsUI() {

    ReadFunctions fun; /* Functions that read the text-files */
    MyFunctions myfun; /* Other functions */
    Toppings toppings; /* The toppings-class */

    char selection = '\0';
    while (selection != 'q') { /* This loop won't end until user selects "Return to Administrator" */

        cout << "Pizzeria_86_Programma (Administrator / Toppings) " << endl;
        cout << "1: Create new Toppings-List (replaces old one)" << endl;
        cout << "2: Add new toppings to Toppings-List" << endl;
        cout << "3: Edit current Toppings-List" << endl;
        cout << "4: See current Toppings-List" << endl;
        cout << "5: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many toppings do you want to add? ";
            cin >> choice;

            ofstream tempfout; /* Here we open and close this file without "ios::app" which removes all the lines in it */
            tempfout.open("ToppingsList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {           /* Here we add "choice" amount of toppings to the toppings list */
                toppings.setVerbose(true);               /* We want extra-text to tell the user what they're *cin-ing* */
                cin >> toppings;                         /* Here we take in the toppings values */
                ofstream fout;
                fout.open("ToppingsList.txt", ios::app); /* Here we open the file with "ios::app" which means we add to it but don't replace any of the other values */
                toppings.setVerbose(false);              /* We don't want extra-text into the file */
                fout << toppings;                        /* Here we put the toppings values into the file */
                fout.close();
            }
        }
        else if (selection == '2') {
            int choice;

            cout << "How many toppings do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                toppings.setVerbose(true);
                cin >> toppings;
                ofstream fout;
                fout.open("ToppingsList.txt", ios::app);
                toppings.setVerbose(false);
                fout << toppings;
                fout.close();
            }
        }
        else if (selection == '3') { /* I don't know how to replace values in the list yet, do that later! */
            cout << "Feature not available (in development)" << endl;
        }
        else if (selection == '4') {
            if (fun.fileExists_ToppingsList()) { /* If the file exists */
                int number_of_lines = fun.get_NumberOfLines_ToppingsList();
                if (number_of_lines != 0) { /* And it's not empty */
                ifstream fin;
                fin.open("ToppingsList.txt");
                    for (int i = 0; i < (number_of_lines / 2); i++) {
                    toppings.setVerbose(false);
                    fin >> toppings;
                    toppings.setVerbose(true);
                    cout << toppings;
                    }
                    fin.close();
                }
                else {
                    cout << "The TypesList is empty" << endl;
                }
            }
            else {
                cout << "The TypesList does not exist" << endl;
            }
        }
        else if (selection == '5') {
            selection = 'q';
        }
    }
}
