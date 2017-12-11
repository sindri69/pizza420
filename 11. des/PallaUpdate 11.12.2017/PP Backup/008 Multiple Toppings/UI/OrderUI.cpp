#include "OrderUI.h"
#include "GetCorrectPizzaUI.h"
#include "UserInputUI.h"
#include "PizzaView.h"

OrderUI::OrderUI() { }

void OrderUI::start_OrdersMenu() {

    UserInputUI ui;
    PizzaView pv;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Sales / Orders)" << endl;
        cout << "1. Make new Pizza" << endl;
        cout << "2. View all Pizzas" << endl;
        cout << "3. Return to Sales" << endl;

        cin >> input;

        if (input == '1') {
            int howmany = ui.getAnswer_Integer("How many Pizzas would you like to add?");
            for (int i = 0; i < howmany; i++) {
                makepizza.make_pizza(create_pizza()); /// Here we make new pizzas
            }
            cout << endl;
        }
        else if (input == '2') { /// Here we view all pizzas
            cout << endl;
            pv.viewPizza();
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

Pizza OrderUI::create_pizza() {
    GetCorrectPizzaUI gp;
    string pID = gp.getCorrectID();
    string pSize = gp.getCorrectSize();
    string pType = gp.getCorrectType();
    string pTopping = gp.getCorrectTopping(pType);
    double pPrice = gp.getCorrectPrice(pID,pSize,pType,pTopping);
    bool pPayedFor = false; /// Would you like to pay now? Function ???
    int pStatus = 1; /// Pizzas always start out as "not made"

    Pizza pizza(pID,pSize,pType,pTopping,pPrice,pPayedFor,pStatus);
    return pizza;
}
