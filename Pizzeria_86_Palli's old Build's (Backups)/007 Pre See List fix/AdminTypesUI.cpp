#include "AdminTypesUI.h"
#include "Types.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

AdminTypesUI::AdminTypesUI()
{
    //ctor
}

AdminTypesUI::~AdminTypesUI()
{
    //dtor
}

void AdminTypesUI::start_adminTypesUI() {
    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Administrator / Types) " << endl;
        cout << "1: Create new Types-List (replaces old one)" << endl;
        cout << "2: Add toppings to Types-List" << endl;
        cout << "3: Edit current Types-List" << endl;
        cout << "4: See current Types-List" << endl;
        cout << "5: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many types do you want to add? ";
            cin >> choice;

            ofstream tempfout;
            tempfout.open("TypesList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {
                Types types;
                types.setVerbose(true);
                cin >> types;
                ofstream fout;
                fout.open("TypesList.txt", ios::app);
                types.setVerbose(false);
                fout << types;
                fout.close();
            }

        }
        else if (selection == '2') {
            int choice;

            cout << "How many types do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Types types;
                types.setVerbose(true);
                cin >> types;
                ofstream fout;
                fout.open("TypesList.txt", ios::app);
                types.setVerbose(false);
                fout << types;
                fout.close();
            }
        }
        else if (selection == '3') {
            cout << "Feature not available (in development)" << endl;
        }
        else if (selection == '4') {
            Types types;
            ifstream fin;
            fin.open("TypesList.txt");

            if (fin.is_open()) {
                int number_of_lines = 0;
                string line;
                ifstream myfile("TypesList.txt");

                while (getline(myfile, line)) {
                    ++number_of_lines;
                }

                for (int i = 0; i < (number_of_lines / 2); i++) {
                    types.setVerbose(false);
                    fin >> types;
                    types.setVerbose(true);
                    cout << types;
                }
                fin.close();
            }
            else {
                cout << "Could not find types list" << endl;
            }
        }
        else if (selection == '5') {
            selection = 'q';
        }
    }
}
