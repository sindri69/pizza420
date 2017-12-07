#include "UI.h"

UI::UI()
{
    //ctor
}

void UI::main_menu(){
    while (choice != 'Q') {
    cout << "Welcome to this awesome salary program!" << endl;
    cout << "What would you like to do?" << endl;
    cout << "****************************************" << endl;
    cout << "1. Add a salary record" << endl;
    cout << "2. Get all salary records for a given SSN" << endl;
    cout << "3. Get a total salary for a given year and a given SSN" << endl;
    cout << "4. Get the name of the employee with the highest total salary for a given year" << endl;
    cout << "5. Quit program!" << endl;
    cin >> choice;


    if(choice== '1'){
        try{
        int howmany;
        cout << "How many employees would you like to add?" << endl;
        cin >> howmany;
        for (int i=0; i<howmany; i++) {
            addemployee.make_employee(create_employee());
            }
        }
        catch(InvalidNameException e) {
        cout << endl;
        }
        catch(InvalidKennitalaException e) {
        cout << endl;
        }
        catch(InvalidSalaryException e) {
        cout << endl;
        }
        catch(InvalidMonthException e){
        cout << endl;
        }
        catch(InvalidYearException e) {
        cout << endl;
        }


    }
    else if(choice == '2'){

    }
    else if(choice == '3') {

    }
    else if (choice == '4'){

    }
    else if(choice == '5') {
        choice = 'Q';
    }
    else {
        cout << "Invalid input!" << endl;
    }
}
}

Employee UI::create_employee() {
        string name;
        string kennitala;
        double salary;
        int month;
        int year;

        cout << "Name: ";
        cin >> ws;
        getline(cin,name); /// ath l\kannski cin a undan
        cout << "Kennitala: ";
        cin >> kennitala;
        cout << "Salary: ";
        cin >> salary;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;

        Employee employee(name, kennitala, salary, month, year);
        return employee;
}
