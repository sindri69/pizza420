#ifndef UI_H
#define UI_H
#include "Employee.h"
#include "EmployeeServices.h"



class UI
{
    public:
        UI();
        void main_menu();
        char choice;

    private:
        Employee create_employee();
        EmployeeServices addemployee;


};

#endif // UI_H
