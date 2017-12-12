#include "ExtraUI.h"
#include "ExtraEdit.h"    /// Change the Extras in the file
#include "ExtraRead.h"    /// Get information from/about the text file
#include "ExtraView.h"    /// Displays Extras to the screen
#include "UserInputUI.h"  /// Gets UserInput
#include "ConstValues.h"

ExtraUI::ExtraUI() { }

void ExtraUI::start_ExtrasMenu() {

    UserInputUI ui;
    ExtraEdit ee;
    ExtraRead er;
    ExtraView ev;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Extras)" << endl;
        cout << "1. Make new Pizza-Extra" << endl;
        cout << "2. View all Pizza-Extras" << endl;
        cout << "3. Delete a Pizza-Extra" << endl;
        cout << "4. Delete all Pizza-Extras" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new Extras, each Extra must contain at least one character, and it can not have the same name as an existing Extra
            try {
                int howmany = ui.getAnswer_Integer("How many Extras would you like to add?");
                for (int i = 0; i < howmany; i++) {
                    makeextra.make_extra(create_extra()); /// Here we make new drinks
                }
                cout << endl;
            }
            catch(InvalidExtraNameNoAlphaException e) {
                cout << "Names must contain at least 1 character that's not a number" << endl << endl;
            }
            catch(InvalidExtraNameAlreadyTakenException e) {
                cout << "That name is already taken" << endl << endl;
            }
            catch(InvalidExtraPriceException e) {
                cout << "Invalid Price!" << endl << endl;
            }
        }
        else if (input == '2') { /// Here we view all drinks on the drinks-list
            cout << endl;
            ev.viewExtra();
            cout << endl;
        }
        else if (input == '3') { /// Here we remove a extra from the drinks list
            if (er.fileNotEmpty()) { /// If the list is empty, there's nothing there to edit ...
                cout << "Extras on the Extras-List" << endl;
                ev.viewExtra(); /// First we display the list of drinks that the user can edit
                cout << endl;
                string whichextra = ui.getAnswer("Which extra would you like to remove?");
                if (ui.answerIsInteger(whichextra)) { /// If answer is an integer, we take the extra that matches that number on the list
                    int whichnum = ui.convert_StringToInteger(whichextra);
                    if ( whichnum <= 0 || whichnum > (er.get_NumberOfLines() / NUMBEROFVALUESINEXTRA) ) {
                        cout << "That number does not match the ones on the list" << endl << endl;
                    }
                    else {
                        ee.deleteExtra(whichnum);
                        cout << endl;
                    }
                }
                else {
                    if (er.check_ExtraAlreadyExists(whichextra)) { /// If answer is not an integer we try to match the user input to the names on the list
                        ee.deleteExtra(whichextra);
                        cout << endl;
                    }
                    else {
                        cout << "That Extra is not on the list" << endl << endl;
                    }
                }
            }
            else {
                cout << "The Extra-List is empty" << endl << endl;
            }
        }
        else if (input == '4') { /// Here we delete all extras in the extras list
            if (ui.getAnswer_Yes_Or_No("Are you sure you want to delete all extras?")) { /// But first we ask if the user is sure ...
                ee.deleteExtra();
                cout << "The Extras List is now empty" << endl;
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

Extra ExtraUI::create_extra() { /// Extras have 4 private values, a name and three price values for (Large/Medium/Small)
    UserInputUI ui;
    string name = ui.getAnswer("Name:");
    double priceL = ui.getAnswer_Double("Price (L):");
    double priceM = ui.getAnswer_Double("Price (M):");
    double priceS = ui.getAnswer_Double("Price (S):");

    Extra extra(name,priceL,priceM,priceS);
    return extra;
}
