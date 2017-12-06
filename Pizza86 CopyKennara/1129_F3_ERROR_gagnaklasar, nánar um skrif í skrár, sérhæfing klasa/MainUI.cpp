#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "PizzaUI.h"
using namespace std;

MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::startUI() {

    char selection = '0';
    while (selection != 'q') {

        cout << "p: pizzas" << endl;
        cout << "w: write" << endl;
        cout << "r: read" << endl;
        cout << "q: quit" << endl;

        cin >> selection;

        if (selection == 'p') {
            PizzaUI pizzaui;
            pizzaui.startUI();
            cout << endl;
        }
        else if (selection == 'w') {
            cout << endl;
        }
        else if (selection == 'r') {
            cout << endl;
        }
    }
}
