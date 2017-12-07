#include "MainUI.h"

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
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
    char input = '0';
    while (input != 'q') {

        cout << "PIZZERIA 86 PROGRAMMA (Administrator / Types)" << endl;
        cout << "1. Make new Pizza-Type" << endl;
        cout << "2. View all Pizza-Types" << endl;
        cout << "3. Delete all Pizza-Types" << endl;
        cout << "4. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') {
            try {
                maketype.make_type(create_type());
                system("CLS");
            }
            catch(InvalidTypeNameException e) {
                system("CLS");
                cout << "That TypeName already exists!" << endl << endl;
            }
            catch(InvalidTypePriceException e) {
                system("CLS");
                cout << "That's not a valid Price" << endl << endl;
            }
        }
        else if (input == '2') {
            cout << "nothing here yet" << endl;
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
Type MainUI::create_type() {
    string name;
    double price;

    cout << "Name: ";
    cin >> ws;
    getline (cin,name);
    cout << "Price: ";
    cin >> price;

    Type type(name,price);
    return type;
}

void MainUI::start_BakingMenu() {
    cout << "hello baker" << endl;
}
void MainUI::start_SalesMenu() {
    cout << "hello sales person" << endl;
}
