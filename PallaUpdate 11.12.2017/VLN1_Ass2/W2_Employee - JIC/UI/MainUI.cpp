#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::start_MainMenu() {

    MyFunctions myfun; /// Mostly functions for getting userInput
    ReadFunctions fun; /// Functions for reading from files

    char input = '0';
    while (input != 'q') {

        cout << "PIZZERIA 86 PROGRAMMA (Administrator / Types)" << endl;
        cout << "1. Add new Employee" << endl;
        cout << "2. View all Employees" << endl;
        cout << "3. View the Employees-list (raw)" << endl;
        cout << "4. Delete the Employees-list" << endl;
        cout << "5. Quit Program" << endl;

        cin >> input;

        if (input == '1') { /// Here we add new employee
            try {
                int howmany = myfun.getAnswer_Integer("How many employees?");
                for (int i = 0; i < howmany; i++) {
                    addemployee.add_employee(create_employee());
                }
                cout << endl;
            }
            catch(InvalidEmployeeNameException e) {
                cout << endl;
            }
            catch(InvalidEmployeeSSNException e) {
                cout << endl;
            }
            catch(InvalidEmployeeSalaryException e) {
                cout << endl;
            }
            catch(InvalidEmployeeMonthException e) {
                cout << endl;
            }
            catch(InvalidEmployeeYearException e) {
                cout << endl;
            }
        }
        else if (input == '2') { /// Here we read from the employee-list
            fun.read_fancy_employee();
            cout << endl;
        }
        else if (input == '3') { /// Here we read all lines in the file
            fun.read_raw_employee();
            cout << endl;
        }
        else if (input == '4') { /// Here we remove all the lines in the file "employee.txt"
            if (myfun.getAnswer_Yes_Or_No("Are you sure you want to delete all information about your employees?")) { /// But first we ask the user if he's sure
                fun.delete_employee();
                cout << "The employee-list is now empty" << endl;
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

Employee MainUI::create_employee() {
    MyFunctions myfun;

    string name = myfun.getAnswer("Name:");
    string ssn = myfun.getAnswer("SSN:");
    double salary = myfun.getAnswer_Double("Salary:");
    int month = myfun.getAnswer_Month("Month:");
    int year = myfun.getAnswer_Integer("Year:");

    Employee employee(name,ssn,salary,month,year);
    return employee;
}
