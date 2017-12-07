#include "TypeMake.h"

TypeMake::TypeMake()
{
    //ctor
}

void TypeMake::make_type(const Type& type) {

    if(isValidTypeName(type) && isValidTypePrice(type)) {
        type_repo.make_type(type);
    }
}

bool TypeMake::isValidTypeName(const Type& type) {

    string name = type.get_name();

    /*
    for (unsigned int i = 0; i < manufacturer.length(); i++) {
        if (!isalpha(manufacturer[i])) { // Ef það eru bókstafir, þá er manufacturer invalid
            throw (InvalidManufacturerException());
        }
    } */

    /// If name is not on list, return true, else throw InvalidTypeNameException()
    return true;
}

bool TypeMake::isValidTypePrice(const Type & type) {
    if (type.get_price() <0) { // Note: Fall sem breytir númer í string
        //string message = "The age " + car.get_age() + " is not valid!";
        string message = "The age is not valid!";
        throw (InvalidTypePriceException(message));
    }
    return true;
}
