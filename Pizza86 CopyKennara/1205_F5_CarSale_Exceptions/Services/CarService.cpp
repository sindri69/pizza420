#include "CarService.h"

CarService::CarService()
{
    //ctor
}

void CarService::add_car(const Car& car) {
    /// validate car
    if(isValidManufacturer(car) && isValidCarAge(car)) {
        car_repo.add_car(car);
    }
}

bool CarService::isValidManufacturer(const Car& car) {

    string manufacturer = car.get_manufacturer();

    for (unsigned int i = 0; i < manufacturer.length(); i++) {
        if (!isalpha(manufacturer[i])) { /* Ef það eru bókstafir, þá er manufacturer invalid */
            throw (InvalidManufacturerException());
        }
    }
    return true;
}

bool CarService::isValidCarAge(const Car & car) {
    if (car.get_age() <0) { // Note: Fall sem breytir númer í string
        //string message = "The age " + car.get_age() + " is not valid!";
        string message = "The age is not valid!";
        throw (InvalidAgeOfCarException(message));
    }
    return true;
}
