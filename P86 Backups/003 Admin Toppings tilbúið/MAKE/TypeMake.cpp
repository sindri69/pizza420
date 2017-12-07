#include "TypeMake.h"
#include "ReadFunctions.h"

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

    ReadFunctions fun;
    if (!fun.check_NameIsAvailable_type(type.get_name())) {
        throw (InvalidTypeNameException());
    }

    return true;
}

bool TypeMake::isValidTypePrice(const Type & type) {
    if (type.get_price() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidTypePriceException());
    }
    return true;
}
