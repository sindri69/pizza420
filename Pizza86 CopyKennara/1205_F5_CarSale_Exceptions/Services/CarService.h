#ifndef CARSERVICE_H
#define CARSERVICE_H

#include "Car.h"
#include "CarRepository.h"
#include "InvalidManufacturerException.h"
#include "InvalidAgeOfCarException.h"

class CarService
{
    public:
        CarService();

        void add_car(const Car& car);

    private:
        CarRepository car_repo;
        bool isValidManufacturer(const Car& car);
        bool isValidCarAge(const Car & car);
};

#endif // CARSERVICE_H
