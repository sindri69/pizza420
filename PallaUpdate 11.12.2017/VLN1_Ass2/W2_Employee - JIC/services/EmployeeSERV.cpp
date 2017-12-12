#include "EmployeeSERV.h"

EmployeeSERV::EmployeeSERV()
{
    //ctor
}

void EmployeeSERV::add_employee(const Employee& employee) {
    if (isValidEmployeeName(employee) && isValidEmployeeSSN(employee) && isValidEmployeeSalary(employee) && isValidEmployeeMonth(employee) && isValidEmployeeYear(employee)) {
        employee_repo.add_employee(employee);
    }
}
bool EmployeeSERV::isValidEmployeeName(const Employee& employee) {
    bool istrue = true; /// Are there any invalid names?
    if (!istrue) {
        throw (InvalidEmployeeNameException());
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeSSN(const Employee& employee) {
    bool istrue = true;
    if (!istrue) {
        throw (InvalidEmployeeSSNException());
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeSalary(const Employee& employee) {
    bool istrue = true;
    if (!istrue) {
        throw (InvalidEmployeeSalaryException());
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeMonth(const Employee& employee) {
    bool istrue = true;
    if (!istrue) {
        throw (InvalidEmployeeMonthException());
    }
    return true;
}
bool EmployeeSERV::isValidEmployeeYear(const Employee& employee) {
    bool istrue = true;
    if (!istrue) {
        throw (InvalidEmployeeYearException());
    }
    return true;
}
