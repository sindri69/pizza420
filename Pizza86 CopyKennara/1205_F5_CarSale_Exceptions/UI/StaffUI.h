#ifndef STAFFUI_H
#define STAFFUI_H

#include "Car.h"
#include "CarService.h"

class StaffUI
{
    public:
        StaffUI();

        void main_menu();

    private:
        Car create_car();
        CarService car_service;
};

#endif // STAFFUI_H
