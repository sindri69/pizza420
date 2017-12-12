#include "TypeUI.h"
#include "TypeView.h"    /// Displays Types to the screen
#include "UserInputUI.h" /// Gets UserInput

TypeUI::TypeUI() { }

void TypeUI::start_TypesMenu() {

    UserInputUI ui;

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Types)" << endl;
        cout << "1. Make new Pizza-Type" << endl;
        cout << "2. View all Pizza-Types" << endl;
        cout << "3. Edit a Pizza-Type" << endl;
        cout << "4. Delete all Pizza-Types" << endl;
        cout << "5. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') { /// Here we make new PizzaTypes, each Type must contain at least one character, and it can not have the same name as an existing type
            try {
                int howmany = ui.getAnswer_Integer("How many Types would you like to add?");
                for (int i = 0; i < howmany; i++) {
                    maketype.make_type(create_type());
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
            TypeView t;
            t.view_type();
            cout << endl;
        }
        else if (input == '3') {

            cout << endl;
        }
        else if (input == '4') {

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
