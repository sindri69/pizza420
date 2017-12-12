#include "TypeUI.h"

TypeUI::TypeUI() { }

void TypeUI::start_TypesMenu() {

    char input = '0';
    while (input != 'q') {

        cout << "PALLA PIZZA (Administrator / Types)" << endl;
        cout << "1. Make new Pizza-Type" << endl;
        cout << "2. View all Pizza-Types" << endl;
        cout << "3. Delete all Pizza-Types" << endl;
        cout << "4. Return to Administrator" << endl;

        cin >> input;

        if (input == '1') {
            try {
                cout << endl;
            }
            catch(InvalidTypeNameException e) {
                cout << endl;
            }
            catch(InvalidTypePriceException e) {
                cout << endl;
            }
        }
        else if (input == '2') {

            cout << endl;
        }
        else if (input == '3') {

            cout << endl;
        }
        else if (input == '4') {
            system("CLS");
            input = 'q';
        }
        else {
            system("CLS");
        }
    }
}

Type TypeUI::create_type() {
    /*
    MyFunctions myfun;
    string name = myfun.getAnswer("Name:");
    double priceL = myfun.getAnswer_Double("Price (L):");
    double priceM = myfun.getAnswer_Double("Price (M):");
    double priceS = myfun.getAnswer_Double("Price (S):");

    Type type(name,priceL,priceM,priceS);
    return type; */
}
