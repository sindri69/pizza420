#include "PizzaUI.h"
#include "PizzaRepository.h"
#include "Pizza.h"
#include <iostream>
using namespace std;

PizzaUI::PizzaUI()
{
    //ctor
}

PizzaUI::~PizzaUI()
{
    //dtor
}

void PizzaUI::startUI() {

    cout << "m: make pizza" << endl;
    cout << "r: read pizza" << endl;

    char selection = '0';
    cin >> selection;

    if (selection == 'm') {
        int topCnt;

        cout << "How many toppings: ";
        cin >> topCnt;

        Pizza pizza(topCnt);

        /* Here Kári said that it'd be smart to show the list of available toppings, and then userInput would be added */
        for(int i = 0; i < topCnt; i++) {

            Topping topping;
            cin >> topping;
            pizza.addTopping(topping);
        }

        cout << pizza << endl;

        PizzaRepository repo;
        repo.storePizza(pizza);

        cout << endl;
    }
    else if (selection == 'r') {

        PizzaRepository repo;
        Pizza pizza = repo.retrievePizza();
        cout << pizza;
        cout << endl;
    }
}

