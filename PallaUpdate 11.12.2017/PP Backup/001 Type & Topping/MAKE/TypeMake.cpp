#include "TypeMake.h"

TypeMake::TypeMake() { }

void TypeMake::make_type(const Type& type) {

    if(isValidTypeName(type) && isValidTypePrice(type)) {
        type_repo.make_type(type);
    }
}

bool TypeMake::isValidTypeName(const Type& type) {
    if (false) {
        throw (InvalidTypeNameException());
    }
    return true;
}

bool TypeMake::isValidTypePrice(const Type & type) {
    if (type.get_priceL() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidTypePriceException());
    }
    if (type.get_priceM() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidTypePriceException());
    }
    if (type.get_priceS() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidTypePriceException());
    }
    return true;
}
