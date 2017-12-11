#include "EmployeeSERV.h"
#include "ReadFunctions.h"
#include "MyFunctions.h"
#include <string>

EmployeeSERV::EmployeeSERV()
{
    //ctor
}

void EmployeeSERV::add_employee(const Employee& employee) {
    ReadFunctions fun; /// Functions that get info about files
    if (isValidEmployeeName(employee) && isValidEmployeeSSN(employee) && isValidEmployeeSalary(employee) && isValidEmployeeMonth(employee) && isValidEmployeeYear(employee)) {
        if (fun.does_old_employee_exist(employee.get_ssn(),employee.get_month(),employee.get_year())) {
            fun.remove_old_employee(fun.find_employeeNUM(employee.get_ssn(),employee.get_month(),employee.get_year()));
            /// If an employee with this SSN, month, year, already exists, we remove him from the list
        }
        employee_repo.add_employee(employee);
    }
}
bool EmployeeSERV::isValidEmployeeName(const Employee& employee) {
    string name = employee.get_name();
    for (size_t i = 0; i < name.length(); i++) {
        if (isdigit(name[i])) {
            cout << "Employee names can not contain numbers" << endl;
            throw (InvalidEmployeeNameException());
        }
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeSSN(const Employee& employee) {
    string ssn = employee.get_ssn();
    if (ssn.length() != 10) {
        cout << "Invalid length of SSN!" << endl;
        throw(InvalidEmployeeSSNException());
    }
    for (size_t i = 0; i < ssn.length(); i++) {
        if (isalpha(ssn[i])) {
            cout << "Only numbers allowed in SSN!" << endl;
            throw(InvalidEmployeeSSNException());
        }
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeSalary(const Employee& employee) {
    if (employee.get_salary() <= 0 || employee.get_salary() > 1000000000) {
        cout << "Invalid employee salary" << endl;
        throw (InvalidEmployeeSalaryException());
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeMonth(const Employee& employee) {
    if (employee.get_month() <= 0 || employee.get_month() > 12) {
        cout << "That month does not exist in the Gregorian calendar" << endl;
        throw (InvalidEmployeeMonthException());
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeYear(const Employee& employee) {
    if (employee.get_year() > 2017 || employee.get_year() < 2000) {
        cout << "That is not a valid year for this company" << endl;
        throw (InvalidEmployeeYearException());
    }
    return true;
}
