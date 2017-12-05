#include "AdminTypesUI.h"
#include "Types.h"
#include "MyFunctions.h"
#include "ReadFunctions.h"
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

    ReadFunctions fun; /* Functions that read the text-files */
    MyFunctions myfun; /* Other functions */
    Types types;       /* The types-class */

    char selection = '\0';
    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Administrator / Types) " << endl;
        cout << "1: Create new Types-List (replaces old one)" << endl;
        cout << "2: Add new type to Types-List" << endl;
        cout << "3: Edit current Types-List" << endl;
        cout << "4: See current Types-List" << endl;
        cout << "5: Return to Administrator" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "Warning! type-names \"Basic\", \"Custom\" and \"Menu\" are reserved" << endl;
            cout << "Using them may cause errors in the system" << endl;
            cout << "How many types do you want to add? ";
            cin >> choice;

            ofstream tempfout;
            tempfout.open("TypesList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {
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

            cout << "Warning! type-names \"Basic\", \"Custom\" and \"Menu\" are reserved" << endl;
            cout << "Using them may cause errors in the system" << endl;
            cout << "How many types do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
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
            if (fun.fileExists_TypesList()) { /* If the file exists */
                int number_of_lines = fun.get_NumberOfLines_TypesList();
                if (number_of_lines != 0) { /* And it's not empty */
                    ifstream fin;
                    fin.open("TypesList.txt");
                    for (int i = 0; i < (number_of_lines / 2); i++) {
                        types.setVerbose(false);
                        fin >> types;
                        types.setVerbose(true);
                        cout << types;
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
