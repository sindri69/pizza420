#include "EmployeeServices.h"
#include "EmployeeRepository.h"

EmployeeServices::EmployeeServices()
{
    //ctor
}

        void EmployeeServices::make_employee(const Employee& employee){
        if(true){
            employee_repo.make_employee(employee);
        }
        }




        bool EmployeeServices::isValidEmployeeName(const Employee& employee){
            bool is_true=true;
            if(!is_true){
                throw (InvalidNameException());
            }
            return true;
        }
        bool EmployeeServices::isValidEmployeekennitala(const Employee& employee){
            bool is_true=true;
            if(!is_true){
                throw (InvalidKennitalaException());
            }
            return true;
        }
        bool EmployeeServices::isValidEmployeeSalary(const Employee& employee){
            bool is_true=true;
            if(!is_true){
                throw (InvalidSalaryException());
            }
            return true;
        }
        bool EmployeeServices::isValidEmployeeMonth(const Employee& employee){
            bool is_true=true;
            if(!is_true){
                throw (InvalidNameException());
            }
            return true;
        }
        bool EmployeeServices::isValidEmployeeYear(const Employee& employee){
            bool is_true=true;
            if(!is_true){
                throw (InvalidNameException());
            }
            return true;
        }


