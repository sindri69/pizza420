#include "OrderUI.h"
#include "GetCorrectPizzaUI.h"
#include "UserInputUI.h"
#include "PizzaView.h"

OrderUI::OrderUI() { }

void OrderUI::start_OrdersMenu() {

    GetCorrectPizzaUI gp;
    UserInputUI ui;
    PizzaView pv;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Sales / Orders)" << endl;
        cout << "1. Make new Order" << endl;
        cout << "2. View all Pizzas" << endl;
        cout << "3. Return to Sales" << endl;

        cin >> input;

        if (input == '1') {
            int howmany = ui.getAnswer_Integer("How many Pizzas would you like to add?");
            string pID = gp.getCorrectID();
            for (int i = 0; i < howmany; i++) {
                makepizza.make_pizza(create_pizza(pID)); /// Here we make new pizzas
            }
            bool lastpizza = false;
            while (!lastpizza) {
                if (ui.getAnswer_Yes_Or_No("Would you like to add another pizza?")) {
                    makepizza.make_pizza(create_pizza(pID)); /// Here we make new pizzas
                }
                else {
                    lastpizza = true;
                }
            }
            /// Would you like a drink ...
            /// Would you like any extras ...
            ///
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

Pizza OrderUI::create_pizza(string pID) {
    GetCorrectPizzaUI gp;
    string pSize = gp.getCorrectSize();
    string pType = gp.getCorrectType();
    string pTopping = gp.getCorrectTopping(pType);
    double pPrice = gp.getCorrectPrice(pID,pSize,pType,pTopping);
    bool pPayedFor = false; /// Would you like to pay now? Function ???
    int pStatus = 1; /// Pizzas always start out as "not made"

    Pizza pizza(pID,pSize,pType,pTopping,pPrice,pPayedFor,pStatus);

    return pizza;
}
