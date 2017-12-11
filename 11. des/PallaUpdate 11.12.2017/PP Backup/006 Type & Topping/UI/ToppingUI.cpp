#include "ToppingUI.h"
#include "ToppingEdit.h"    /// Change the Toppings in the file
#include "ToppingRead.h"    /// Get information from/about the text file
#include "ToppingView.h"    /// Displays Toppings to the screen
#include "UserInputUI.h"    /// Gets UserInput
#include "ConstValues.h"

ToppingUI::ToppingUI() { }

void ToppingUI::start_ToppingsMenu() {

    UserInputUI ui;
    ToppingEdit te;
    ToppingRead tr;
    ToppingView tv;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Toppings)" << endl;
        cout << "1. Make new Pizza-Topping" << endl;
        cout << "2. View all Pizza-Toppings" << endl;
        cout << "3. Delete a Pizza-Topping" << endl;
        cout << "4. Delete all Pizza-Toppings" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new PizzaToppings, each Topping must contain at least one character, and it can not have the same name as an existing topping
            try {
                int howmany = ui.getAnswer_Integer("How many Toppings would you like to add?");
                for (int i = 0; i < howmany; i++) {
                    maketopping.make_topping(create_topping()); /// Here we make new toppings
                }
                cout << endl;
            }
            catch(InvalidToppingNameNoAlphaException e) {
                cout << "Names must contain at least 1 character that's not a number" << endl << endl;
            }
            catch(InvalidToppingNameAlreadyTakenException e) {
                cout << "That name is already taken" << endl << endl;
            }
            catch(InvalidToppingPriceException e) {
                cout << "Invalid Price!" << endl << endl;
            }
        }
        else if (input == '2') { /// Here we view all toppings on the toppings-list
            cout << endl;
            tv.viewTopping();
            cout << endl;
        }
        else if (input == '3') { /// Here we remove a topping from the toppings list
            if (tr.fileNotEmpty()) { /// If the list is empty, there's nothing there to edit ...
                cout << "Toppings on the Toppings-List" << endl;
                tv.viewTopping(); /// First we display the list of toppings that the user can edit
                cout << endl;
                string whichtopping = ui.getAnswer("Which topping would you like to remove?");
                if (ui.answerIsInteger(whichtopping)) { /// If answer is an integer, we take the topping that matches that number on the list
                    int whichnum = ui.convert_StringToInteger(whichtopping);
                    if ( whichnum <= 0 || whichnum > (tr.get_NumberOfLines() / NUMBEROFVALUESINTOPPING) ) {
                        cout << "That number does not match the ones on the list" << endl << endl;
                    }
                    else {
                        te.deleteTopping(whichnum);
                        cout << endl;
                    }
                }
                else {
                    if (tr.check_ToppingAlreadyExists(whichtopping)) { /// If answer is not an integer we try to match the user input to the names on the list
                        te.deleteTopping(whichtopping);
                        cout << endl;
                    }
                    else {
                        cout << "That Topping is not on the list" << endl << endl;
                    }
                }
            }
            else {
                cout << "The Topping-List is empty" << endl << endl;
            }
        }
        else if (input == '4') { /// Here we delete all toppings in the toppings list
            if (ui.getAnswer_Yes_Or_No("Are you sure you want to delete all pizza toppings?")) { /// But first we ask if the user is sure ...
                te.deleteTopping();
                cout << "The Toppings List is now empty" << endl;
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

Topping ToppingUI::create_topping() { /// Toppings have 4 private values, a name and three price values for (Large/Medium/Small)
    UserInputUI ui;
    string name = ui.getAnswer("Name:");
    double priceL = ui.getAnswer_Double("Price (L):");
    double priceM = ui.getAnswer_Double("Price (M):");
    double priceS = ui.getAnswer_Double("Price (S):");

    Topping topping(name,priceL,priceM,priceS);
    return topping;
}
