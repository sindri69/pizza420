#include "ToppingUI.h"

ToppingUI::ToppingUI() { }

void ToppingUI::start_ToppingsMenu() {
    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Toppings)" << endl;
        cout << "1. Make new Pizza-Topping" << endl;
        cout << "2. View all Pizza-Toppings" << endl;
        cout << "3. Edit Pizza-Topping" << endl;
        cout << "4. Delete all Pizza-Toppings" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') {

            cout << endl;
        }
        else if (input == '2') {

            cout << endl;
        }
        else if (input == '3') {

            cout << endl;
        }
        else if (input == '4') {

            cout << endl;
        }
        else if (input == '5') {
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS");
        }
    }
}

Topping ToppingUI::create_topping() {
/*
    string name = myfun.getAnswer("Name:");
    double priceL = myfun.getAnswer_Double("Price (L):");
    double priceM = myfun.getAnswer_Double("Price (M):");
    double priceS = myfun.getAnswer_Double("Price (S):");

    Topping topping(name,priceL,priceM,priceS);
    return topping;*/
}
