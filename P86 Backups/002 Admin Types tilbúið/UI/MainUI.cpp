#include "MainUI.h"
#include "ReadFunctions.h" /// Functions that read from text files
#include "MyFunctions.h"  /// Other functions (some redundant)

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
#include <fstream>
using namespace std;

MainUI::MainUI()
{
    //ctor
}

void MainUI::start_MainMenu() {

    char input = '0';
    while (input != 'q') {

        cout << "PIZZERIA 86 PROGRAMMA" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Bakery" << endl;
        cout << "3. Sales (Orders / Payments / Delivery)" << endl;
        cout << "4. Quit Program" << endl;

        cin >> input;

        if (input == '1') {
            system("CLS");
            start_AdminMenu();
        }
        else if (input == '2') {
            start_BakingMenu();
        }
        else if (input == '3') {
            start_SalesMenu();
        }
        else if (input == '4') {
            cout << "Arrivederci" << endl;
            input = 'q';
        }
        else {
            system("CLS");
        }
    }
}

void MainUI::start_AdminMenu() {

    char input = '0';
    while (input != 'q') {

        cout << "PIZZERIA 86 PROGRAMMA (Administrator)" << endl;
        cout << "1. Go to Pizza" << endl;
        cout << "2. Go to Types" << endl;
        cout << "3. Go to Toppings" << endl;
        cout << "4. Return to Main" << endl;

        cin >> input;

        if (input == '1') {
            cout << "nothing here yet" << endl;
        }
        else if (input == '2') {
            system("CLS");
            start_AdminTypesMenu();
        }
        else if (input == '3') {
            cout << "nothing here yet" << endl;
        }
        else if (input == '4') {
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS"); /// This cleans our screen, makes it more neat !
        }
    }
}

void MainUI::start_AdminTypesMenu() {

    MyFunctions myfun; /// Mostly functions for getting userInput
    ReadFunctions fun; /// Functions for reading from files

    char input = '0';
    while (input != 'q') {

        cout << "PIZZERIA 86 PROGRAMMA (Administrator / Types)" << endl;
        cout << "1. Make new Pizza-Type" << endl;
        cout << "2. View all Pizza-Types" << endl;
        cout << "3. View the Pizza-Types-List (raw)" << endl;
        cout << "4. Delete all Pizza-Types" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new pizza-types
            try {
                int howmany = myfun.getAnswer_Integer("How many types would you like to add?");
                for (int i = 0; i < howmany; i++) {
                    maketype.make_type(create_type());
                }
                cout << endl;
            }
            catch(InvalidTypeNameException e) {
                cout << endl;
            }
            catch(InvalidTypePriceException e) {
                cout << endl;
            }
        }
        else if (input == '2') { /// Here we read from the types-list
            fun.read_fancy_type();
            cout << endl;
        }
        else if (input == '3') { /// Here we read all lines in the file
            fun.read_raw_type();
            cout << endl;
        }
        else if (input == '4') { /// Here we remove all the lines in the file "type.txt"
            if (myfun.getAnswer_Yes_Or_No("Are you sure you want to delete all Pizza-Types?")) { /// But first we ask the user if he's sure
                fun.delete_type();
                cout << "The Types-List is now empty" << endl;
            }
            else {
                cout << "Deletion canceled" << endl;
            }
            cout << endl;
        }
        else if (input == '5') {
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS"); /// This cleans our screen, makes it more neat !
        }
    }
}

void MainUI::start_BakingMenu() {
    cout << "hello baker" << endl;
}
void MainUI::start_SalesMenu() {
    cout << "hello sales person" << endl;
}

Type MainUI::create_type() {
    MyFunctions myfun;
    string name = myfun.getAnswer("Name:");
    double price = myfun.getAnswer_Double("Price:");

    Type type(name,price);
    return type;
}


