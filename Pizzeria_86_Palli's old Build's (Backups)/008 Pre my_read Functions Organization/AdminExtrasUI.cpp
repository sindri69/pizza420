#include "AdminExtrasUI.h"
#include "Extras.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminExtrasUI::AdminExtrasUI()
{
    //ctor
}

AdminExtrasUI::~AdminExtrasUI()
{
    //dtor
}

void AdminExtrasUI::start_adminExtrasUI() {
    char selection = '\0';

    while (selection != 'q') { /* This loop won't end until user selects "Return to Administrator" */

        cout << "Pizzeria_86_Programma (Administrator / Extras) " << endl;
        cout << "1: Create new Extras-List (replaces old one)" << endl;
        cout << "2: Add extras to Extras-List" << endl;
        cout << "3: Edit current Extras-List" << endl;
        cout << "4: See current Extras-List" << endl;
        cout << "5: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many extras do you want to add? ";
            cin >> choice;

            ofstream tempfout; /* Here we open and close this file without "ios::app" which removes all the lines in it */
            tempfout.open("ExtrasList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {         /* Here we add "choice" amount of extras to the list */
                Extras extras;                         /* Here we are using values from Extras.h */
                extras.setVerbose(true);               /* We want extra-text to tell the user what they're *cin-ing* */
                cin >> extras;                         /* Here we take in the values */
                ofstream fout;
                fout.open("ExtrasList.txt", ios::app); /* Here we open the file with "ios::app" which means we add to it but don't replace any of the other values */
                extras.setVerbose(false);              /* We don't want extra-text into the file */
                fout << extras;                        /* Here we put the values into the file */
                fout.close();
            }
        }
        else if (selection == '2') {
            int choice;

            cout << "How many extras do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Extras extras;
                extras.setVerbose(true);
                cin >> extras;
                ofstream fout;
                fout.open("ExtrasList.txt", ios::app);
                extras.setVerbose(false);
                fout << extras;
                fout.close();
            }
        }
        else if (selection == '3') { /* I don't know how to replace values in the list besides just, do that later! */
            cout << "Feature not available (in development)" << endl;
        }
        else if (selection == '4') {
            Extras extras;
            ifstream fin;
            fin.open("ExtrasList.txt");

            if (fin.is_open()) {
                int number_of_lines = 0;
                string line;
                ifstream myfile("ExtrasList.txt");

                while (getline(myfile, line)) {
                    ++number_of_lines;
                }

                for (int i = 0; i < (number_of_lines / 2); i++) {
                    extras.setVerbose(false);
                    fin >> extras;
                    extras.setVerbose(true);
                    cout << extras;
                }
                fin.close();
            }
            else {
                cout << "Could not find extras list" << endl;
            }
        }
        else if (selection == '5') {
            selection = 'q';
        }
    }
}
