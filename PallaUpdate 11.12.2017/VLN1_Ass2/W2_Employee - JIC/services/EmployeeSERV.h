#ifndef EMPLOYEESERV_H
#define EMPLOYEESERV_H

#include "Employee.h"
#include "EmployeeREPO.h"
#include "InvalidEmployeeNameException.h"
#include "InvalidEmployeeSSNException.h"
#include "InvalidEmployeeSalaryException.h"
#include "InvalidEmployeeMonthException.h"
#include "InvalidEmployeeYearException.h"

class EmployeeSERV
{
    public:
        EmployeeSERV();

        void add_employee(const Employee& employee);

    private:
        EmployeeREPO employee_repo;
        bool isValidEmployeeName(const Employee& employee);
        bool isValidEmployeeSSN(const Employee& employee);
        bool isValidEmployeeSalary(const Employee& employee);
        bool isValidEmployeeMonth(const Employee& employee);
        bool isValidEmployeeYear(const Employee& employee);
};

#endif // EMPLOYEESERV_H
