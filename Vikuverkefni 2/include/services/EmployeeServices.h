#ifndef EMPLOYEESERVICES_H
#define EMPLOYEESERVICES_H
#include "Employee.h"
#include "EmployeeRepository.h"
#include "InvalidNameException.h"
#include "InvalidKennitalaException.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"



class EmployeeServices
{
    public:
        EmployeeServices();

        void make_employee(const Employee& employee);


    private:
        EmployeeRepository employee_repo;
        bool isValidEmployeeName(const Employee& employee);
        bool isValidEmployeekennitala(const Employee& employee);
        bool isValidEmployeeSalary(const Employee& employee);
        bool isValidEmployeeMonth(const Employee& employee);
        bool isValidEmployeeYear(const Employee& employee);
};

#endif // EMPLOYEESERVICES_H
