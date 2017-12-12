#include "PizzaUI.h"
#include "PizzaRead.h"
#include "PizzaEdit.h"
#include "PizzaView.h"
#include "BasicView.h"
#include "UserInputUI.h"

PizzaUI::PizzaUI() { }

void PizzaUI::start_PizzaMenu() {

    BasicView bv;
    PizzaView pv;
    PizzaEdit pe;
    UserInputUI ui;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Pizza)" << endl;
        cout << "1. Set prize for \"Basic\" (L/M/S)" << endl;
        cout << "2. See prize for \"Basic\" (L/M/S)" << endl;
        cout << "3. View all Pizza-Orders" << endl;
        cout << "4. Delete all Pizza-Orders" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we set new prices for "Basic" Pizza type
            try {
                makebasic.make_basic(create_basic());
                cout << endl;
            }
            catch(InvalidBasicPriceException e) {
                cout << endl;
            }
        }
        else if (input == '2') { /// Here we see the current prices for "Basic" Pizza type
            cout << endl;
            bv.view_basic();
            cout << endl;
        }
        else if (input == '3') { /// Here we read from the toppings-list
            cout << endl;
            pv.viewPizza();
            cout << endl;
        }
        else if (input == '4') { /// Here we remove all the lines in the file "pizza.txt"
            if (ui.getAnswer_Yes_Or_No("Are you sure you want to delete all pizzas?")) { /// But first we ask if the user is sure he wants to delete all types
                pe.deletePizza();
                cout << "The Pizza List is now empty" << endl;
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
            system("CLS");
        }
    }
}

Basic PizzaUI::create_basic() {
    UserInputUI ui;
    double priceL = ui.getAnswer_Double("Price (L):");
    double priceM = ui.getAnswer_Double("Price (M):");
    double priceS = ui.getAnswer_Double("Price (S):");

    Basic basic(priceL,priceM,priceS);
    return basic;
}
