#include "TypeUI.h"
#include "TypeEdit.h"    /// Change the Types in the file
#include "TypeRead.h"    /// Get information from/about the text file
#include "TypeView.h"    /// Displays Types to the screen
#include "UserInputUI.h" /// Gets UserInput
#include "ConstValues.h"

TypeUI::TypeUI() { }

void TypeUI::start_TypesMenu() {

    UserInputUI ui;
    TypeEdit te;
    TypeRead tr;
    TypeView tv;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Types)" << endl;
        cout << "1. Make new Pizza-Type" << endl;
        cout << "2. View all Pizza-Types" << endl;
        cout << "3. Delete a Pizza-Type" << endl;
        cout << "4. Delete all Pizza-Types" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new PizzaTypes, each Type must contain at least one character, and it can not have the same name as an existing type
            try {
                int howmany = ui.getAnswer_Integer("How many Types would you like to add?");
                for (int i = 0; i < howmany; i++) {
                    maketype.make_type(create_type()); /// Here we make new types
                }
                cout << endl;
            }
            catch(InvalidTypeNameNoAlphaException e) {
                cout << "Names must contain at least 1 character that's not a number" << endl << endl;
            }
            catch(InvalidTypeNameAlreadyTakenException e) {
                cout << "That name is already taken" << endl << endl;
            }
            catch(InvalidTypePriceException e) {
                cout << "Invalid Price!" << endl << endl;
            }
        }
        else if (input == '2') { /// Here we view all types on the types-list
            cout << endl;
            tv.view_type();
            cout << endl;
        }
        else if (input == '3') { /// Here we change the name / price of an already existing type
            if (tr.fileNotEmpty_type()) { /// If the list is empty, there's nothing there to edit ...
                cout << "Types on the Types-List" << endl;
                tv.view_type(); /// First we display the list of types that the user can edit
                cout << endl;
                string whichtype = ui.getAnswer("Which type would you like to remove?");
                if (ui.answerIsInteger(whichtype)) { /// If answer is an integer, we take the type that matches that number on the list
                    int whichnum = ui.convert_StringToInteger(whichtype);
                    if ( whichnum <= 0 || whichnum > (tr.get_NumberOfLines_type() / NUMBEROFVALUESINTYPE) ) {
                        cout << "That number does not match the ones on the list" << endl << endl;
                    }
                    else {
                        te.delete_type(whichnum);
                        cout << endl;
                    }
                }
                else {
                    if (tr.check_TypeAlreadyExists_type(whichtype)) { /// If answer is not an integer we try to match the user input to the names on the list
                        te.delete_type(whichtype);
                        cout << endl;
                    }
                    else {
                        cout << "That Type is not on the list" << endl << endl;
                    }
                }
            }
            else {
                cout << "The Type-List is empty" << endl << endl;
            }
        }
        else if (input == '4') { /// Here we delete all types in the types list
            if (ui.getAnswer_Yes_Or_No("Are you sure you want to delete all pizza types?")) { /// But first we ask if the user is sure he wants to delete all types
                te.delete_type();
                cout << "The Types List is now empty" << endl;
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

Type TypeUI::create_type() { /// Types have 4 private values, a name and three price values for (Large/Medium/Small)
    UserInputUI ui;
    string name = ui.getAnswer("Name:");
    double priceL = ui.getAnswer_Double("Price (L):");
    double priceM = ui.getAnswer_Double("Price (M):");
    double priceS = ui.getAnswer_Double("Price (S):");

    Type type(name,priceL,priceM,priceS);
    return type;
}
