#include "MainUI.h"
#include "PizzaUI.h"
#include "TypeUI.h"
#include "ToppingUI.h"

MainUI::MainUI() { }

void MainUI::start_MainMenu() {

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA" << endl;
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
            system("CLS");
            start_SalesMenu();
        }
        else if (input == '4') {
            cout << "Arrivederci" << endl; /// This is Italian for goodbye, well... that's what GoogleTranslate said ...
            input = 'q';
        }
        else {
            system("CLS"); /// This cleans the screen, I only use it when moving between different menus, and when user gives invalid input
        }
    }
}

void MainUI::start_AdminMenu() {

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator)" << endl; /// In the primary menus I always show a "path/location" so the user does not get lost :)
        cout << "1. Go to Pizza" << endl;
        cout << "2. Go to Types" << endl;
        cout << "3. Go to Toppings" << endl;
        cout << "4. Return to Main" << endl;

        cin >> input;

        if (input == '1') { /// Jump to PizzaMenu
            system("CLS");
            PizzaUI p;
            p.start_PizzaMenu();
        }
        else if (input == '2') { /// Jump to TypesMenu
            system("CLS");
            TypeUI t;
            t.start_TypesMenu();
        }
        else if (input == '3') { /// Jump to ToppingsMenu
            system("CLS");
            ToppingUI t;
            t.start_ToppingsMenu();
        }
        else if (input == '4') { /// Return to MainMenu
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS");
        }
    }
}

void MainUI::start_BakingMenu() {
    cout << "Not here yet :(" << endl;
}

void MainUI::start_SalesMenu() {

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Sales)" << endl;
        cout << "1. Make new Pizza" << endl;
        cout << "2. View all Pizzas" << endl;
        cout << "3. Main" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new pizzas
            cout << endl;
        }
        else if (input == '2') { /// Here we view all pizzas
            cout << endl;
        }
        else if (input == '3') {
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS");
        }
    }
}
