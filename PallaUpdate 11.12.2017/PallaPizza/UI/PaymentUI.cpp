#include "PaymentUI.h"
#include "PizzaEdit.h"
#include "PizzaRead.h"
#include "PizzaView.h"
#include "UserInputUI.h"

PaymentUI::PaymentUI() { }

void PaymentUI::start_PaymentsMenu() {

    PizzaEdit pe;
    PizzaRead pr;
    PizzaView pv;
    UserInputUI ui;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Sales / Payments)" << endl;
        cout << "1. Pay for Pizza" << endl;
        cout << "2. View all Pizzas" << endl;
        cout << "3. View all Pizzas (Matching pID)" << endl;
        cout << "4. View all Pizzas (Already payed)" << endl;
        cout << "5. View all Pizzas (Not payed for)" << endl;
        cout << "6. Return to Sales" << endl;

        cin >> input;

        if (input == '1') {
            cout << endl;
            string whichID = ui.getAnswer("Which pID do you want to pay for?");
            cout << endl;
            if (pr.check_PizzaIDAlreadyExists(whichID)) {
                pv.viewPizza(whichID);
                cout << endl;
                cout << "Total cost for order = " << pr.getTotalPrice(whichID) << endl;
                if (ui.getAnswer_Yes_Or_No("Are you sure you wish to pay for this order?")) {
                    pe.payforPizza(whichID);
                    cout << "Transaction complete" << endl;
                }
                else {
                    cout << "Payment canceled" << endl;
                }
            }
            else {
                cout << "There are no Pizzas with that pID" << endl;
            }
            cout << endl;
        }
        else if (input == '2') { /// Here we view all pizzas
            cout << endl;
            pv.viewPizza();
            cout << endl;
        }
        else if (input == '3') { /// Here we view all pizzas matching a specific pID
            cout << endl;
            string whichID = ui.getAnswer("Which pID would you like to view?");
            if (pr.check_PizzaIDAlreadyExists(whichID)) {
                pv.viewPizza(whichID);
            }
            else {
                cout << "There are no Pizzas with that pID" << endl;
            }
            cout << endl;
        }
        else if (input == '4') { /// Here we view all pizzas that have been payed for
            cout << endl;
            pv.viewPizza_PayedFor();
            cout << endl;
        }
        else if (input == '5') { /// Here we view all pizzas that have not been payed for
            cout << endl;
            pv.viewPizza_NotPayed();
            cout << endl;
        }
        else if (input == '6') {
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS");
        }
    }
}
