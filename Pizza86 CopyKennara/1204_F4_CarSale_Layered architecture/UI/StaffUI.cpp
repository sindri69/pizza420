#include "StaffUI.h"

StaffUI::StaffUI()
{
    //ctor
}

void StaffUI::main_menu() {

    cout << "Welcome to Car Program" << endl;

    char input = '0';
    while (input != 'q') {
        cout << "MAIN MENU - OF CAR PLACE" << endl;
        cout << "1. Add a car" << endl;
        cout << "2. View cars" << endl;
        cout << "3. Quit" << endl;
        cout << endl;

        cin >> input;

        if (input == '1') {
            car_service.add_car(create_car());
        }
        else if (input == '2') {
            cout << "viewing cars" << endl;
        }
        else if (input == '3') {
            cout << "Goodbye Staff Person" << endl;
            input = 'q';
        }
        else {
            cout << "invalid input!" << endl;
        }
    }
}

Car StaffUI::create_car() {
    string manufacturer, type;
    int age;

    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Type: ";
    cin >> type;
    cout << "Age: ";
    cin >> age;

    Car car(manufacturer, type, age);
    return car;
}
