#include "AdminDrinksUI.h"
#include "Drinks.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminDrinksUI::AdminDrinksUI()
{
    //ctor
}

AdminDrinksUI::~AdminDrinksUI()
{
    //dtor
}

void AdminDrinksUI::start_adminDrinksUI() {
    char selection = '\0';

    while (selection != 'q') { /* This loop won't end until user selects "Return to Administrator" */

        cout << "Pizzeria_86_Programma (Administrator / Drinks) " << endl;
        cout << "1: Create new Drinks-List (replaces old one)" << endl;
        cout << "2: Add drinks to Drinks-List" << endl;
        cout << "3: Edit current Drinks-List" << endl;
        cout << "4: See current Drinks-List" << endl;
        cout << "5: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many drinks do you want to add? ";
            cin >> choice;

            ofstream tempfout; /* Here we open and close this file without "ios::app" which removes all the lines in it */
            tempfout.open("DrinksList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {         /* Here we add "choice" amount of drinks to the list */
                Drinks drinks;                         /* Here we are calling Drinks.h */
                drinks.setVerbose(true);               /* We want extra-text to tell the user what they're *cin-ing* */
                cin >> drinks;                         /* Here we take in the values */
                ofstream fout;
                fout.open("DrinksList.txt", ios::app); /* Here we open the file with "ios::app" which means we add to it but don't replace any of the other values */
                drinks.setVerbose(false);              /* We don't want extra-text into the file */
                fout << drinks;                        /* Here we put the values into the file */
                fout.close();
            }
        }
        else if (selection == '2') {
            int choice;

            cout << "How many drinks do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Drinks drinks;
                drinks.setVerbose(true);
                cin >> drinks;
                ofstream fout;
                fout.open("DrinksList.txt", ios::app);
                drinks.setVerbose(false);
                fout << drinks;
                fout.close();
            }
        }
        else if (selection == '3') { /* I don't know how to replace values in the list besides just, do that later! */
            cout << "Feature not available (in development)" << endl;
        }
        else if (selection == '4') {
            Drinks drinks;
            ifstream fin;
            fin.open("DrinksList.txt");

            if (fin.is_open()) {
                int number_of_lines = 0;
                string line;
                ifstream myfile("DrinksList.txt");

                while (getline(myfile, line)) {
                    ++number_of_lines;
                }

                for (int i = 0; i < (number_of_lines / 2); i++) {
                    drinks.setVerbose(false);
                    fin >> drinks;
                    drinks.setVerbose(true);
                    cout << drinks;
                }
                fin.close();
            }
            else {
                cout << "Could not find drinks list" << endl;
            }
        }
        else if (selection == '5') {
            selection = 'q';
        }
    }
}
