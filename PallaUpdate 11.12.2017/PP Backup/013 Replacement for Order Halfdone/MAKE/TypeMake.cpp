#include "TypeMake.h"
#include "TypeRead.h"
#include "UserInputUI.h"

TypeMake::TypeMake() { }

void TypeMake::make_type(const Type& type) {

    if(isValidTypeName(type) && isValidTypePrice(type)) {
        type_repo.make_type(type);
    }
}

bool TypeMake::isValidTypeName(const Type& type) {
    UserInputUI ui;
    bool hasAlpha = false;
    string name = type.get_name();
    if (ui.convert_StringToLowerCase(name) == "basic") { /// The type-name "Basic" is reserved
        throw (InvalidTypeNameBasicIsReservedException());
    }
    if (ui.convert_StringToLowerCase(name) == "custom") { /// The type-name "Custom" is reserved
        throw (InvalidTypeNameCustomIsReservedException());
    }
    for (unsigned int i = 0; i < name.size(); i++) { /// Here we're making sure that the name has at least one character that's not a number
        if (isalpha(name[i])) {
            hasAlpha = true;
            break;
        }
    }
    if (!hasAlpha) {
        throw (InvalidTypeNameNoAlphaException());
    }
    TypeRead t;
    if (t.check_TypeAlreadyExists(name)) {
        throw (InvalidTypeNameAlreadyTakenException());
    }
    return true;
}

bool TypeMake::isValidTypePrice(const Type & type) { /// Prices must be numbers, there is a conversion function that converts strings to int/double, if that fails it turns the value to zero
    if (type.get_priceL() <= 0) {                    /// So we just have to make sure that the number is not zero or lower
        throw (InvalidTypePriceException());
    }
    if (type.get_priceM() <= 0) {
        throw (InvalidTypePriceException());
    }
    if (type.get_priceS() <= 0) {
        throw (InvalidTypePriceException());
    }
    if (type.get_priceL() < type.get_priceM() || type.get_priceM() < type.get_priceS()) { /// Prices should be Large > Medium > Small
        throw (InvalidTypePriceException());
    }
    return true;
}
