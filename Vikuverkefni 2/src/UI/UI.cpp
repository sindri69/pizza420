#include "UI.h"

UI::UI()
{
    //ctor
}

void UI::main_menu(){
    cout << "Welcome to this awesome salary program!" << endl;
    cout << "What would you like to do?" << endl;
    cout << "****************************************" << endl;
    cout << "1. Add a salary record" << endl;
    cout << "2. Get all salary records for a given SSN" << endl;
    cout << "3. Get a total salary for a given year and a given SSN" << endl;
    cout << "4. Get the name of the employee with the highest total salary for a given year" << endl;
    cin >> choice;
}
