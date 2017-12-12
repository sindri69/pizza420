#include "DrinkUI.h"
#include "DrinkEdit.h"    /// Change the Drinks in the file
#include "DrinkRead.h"    /// Get information from/about the text file
#include "DrinkView.h"    /// Displays Drinks to the screen
#include "UserInputUI.h"  /// Gets UserInput
#include "ConstValues.h"

DrinkUI::DrinkUI() { }

void DrinkUI::start_DrinksMenu() {

    UserInputUI ui;
    DrinkEdit de;
    DrinkRead dr;
    DrinkView dv;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Drinks)" << endl;
        cout << "1. Make new Pizza-Drink" << endl;
        cout << "2. View all Pizza-Drinks" << endl;
        cout << "3. Delete a Pizza-Drink" << endl;
        cout << "4. Delete all Pizza-Drinks" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new Drinks, each Drink must contain at least one character, and it can not have the same name as an existing Drink
            try {
                int howmany = ui.getAnswer_Integer("How many Drinks would you like to add?");
                for (int i = 0; i < howmany; i++) {
                    makedrink.make_drink(create_drink()); /// Here we make new drinks
                }
                cout << endl;
            }
            catch(InvalidDrinkNameNoAlphaException e) {
                cout << "Names must contain at least 1 character that's not a number" << endl << endl;
            }
            catch(InvalidDrinkNameAlreadyTakenException e) {
                cout << "That name is already taken" << endl << endl;
            }
            catch(InvalidDrinkPriceException e) {
                cout << "Invalid Price!" << endl << endl;
            }
        }
        else if (input == '2') { /// Here we view all drinks on the drinks-list
            cout << endl;
            dv.viewDrink();
            cout << endl;
        }
        else if (input == '3') { /// Here we remove a drink from the drinks list
            if (dr.fileNotEmpty()) { /// If the list is empty, there's nothing there to edit ...
                cout << "Drinks on the Drinks-List" << endl;
                dv.viewDrink(); /// First we display the list of drinks that the user can edit
                cout << endl;
                string whichdrink = ui.getAnswer("Which drink would you like to remove?");
                if (ui.answerIsInteger(whichdrink)) { /// If answer is an integer, we take the drink that matches that number on the list
                    int whichnum = ui.convert_StringToInteger(whichdrink);
                    if ( whichnum <= 0 || whichnum > (dr.get_NumberOfLines() / NUMBEROFVALUESINDRINK) ) {
                        cout << "That number does not match the ones on the list" << endl << endl;
                    }
                    else {
                        de.deleteDrink(whichnum);
                        cout << endl;
                    }
                }
                else {
                    if (dr.check_DrinkAlreadyExists(whichdrink)) { /// If answer is not an integer we try to match the user input to the names on the list
                        de.deleteDrink(whichdrink);
                        cout << endl;
                    }
                    else {
                        cout << "That Drink is not on the list" << endl << endl;
                    }
                }
            }
            else {
                cout << "The Drink-List is empty" << endl << endl;
            }
        }
        else if (input == '4') { /// Here we delete all drinks in the drinks list
            if (ui.getAnswer_Yes_Or_No("Are you sure you want to delete all drinks?")) { /// But first we ask if the user is sure ...
                de.deleteDrink();
                cout << "The Drinks List is now empty" << endl;
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

Drink DrinkUI::create_drink() { /// Drinks have 4 private values, a name and three price values for (Large/Medium/Small)
    UserInputUI ui;
    string name = ui.getAnswer("Name:");
    double priceL = ui.getAnswer_Double("Price (L):");
    double priceM = ui.getAnswer_Double("Price (M):");
    double priceS = ui.getAnswer_Double("Price (S):");

    Drink drink(name,priceL,priceM,priceS);
    return drink;
}
