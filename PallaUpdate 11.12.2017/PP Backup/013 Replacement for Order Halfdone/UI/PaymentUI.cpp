#include "PaymentUI.h"
#include "PizzaEdit.h"
#include "PizzaView.h"
#include "UserInputUI.h"

PaymentUI::PaymentUI() { }

void PaymentUI::start_PaymentsMenu() {

    PizzaEdit pe;
    PizzaView pv;
    UserInputUI ui;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Sales / Payments)" << endl;
        cout << "1. Pay for Pizza" << endl;
        cout << "2. View all Pizzas" << endl;
        cout << "3. View all Pizzas (Already payed)" << endl;
        cout << "4. View all Pizzas (Not payed for)" << endl;
        cout << "5. Return to Sales" << endl;

        cin >> input;

        if (input == '1') {
            cout << endl;
            pv.viewPizza_NotPayed();






            cout << endl;
        }
        else if (input == '2') { /// Here we view all pizzas
            cout << endl;
            pv.viewPizza();
            cout << endl;
        }
           else if (input == '3') { /// Here we view all pizzas that have been payed for
            cout << endl;
            pv.viewPizza_PayedFor();
            cout << endl;
        }
           else if (input == '4') { /// Here we view all pizzas that have not been payed for
            cout << endl;
            pv.viewPizza_NotPayed();
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
