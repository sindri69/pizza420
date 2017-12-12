#include "ToppingMake.h"
#include "ToppingRead.h"

ToppingMake::ToppingMake() { }

void ToppingMake::make_topping(const Topping& topping) {

    if(isValidToppingName(topping) && isValidToppingPrice(topping)) {
        topping_repo.make_topping(topping);
    }
}

bool ToppingMake::isValidToppingName(const Topping& topping) {
    bool hasAlpha = false;
    string name = topping.get_name();
    for (unsigned int i = 0; i < name.size(); i++) { /// Here we're making sure that the name has at least one character that's not a number
        if (isalpha(name[i])) {
            hasAlpha = true;
            break;
        }
    }
    if (!hasAlpha) {
        throw (InvalidToppingNameNoAlphaException());
    }
    ToppingRead t;
    if (t.check_ToppingAlreadyExists(name)) {
        throw (InvalidToppingNameAlreadyTakenException());
    }
    return true;
}

bool ToppingMake::isValidToppingPrice(const Topping & topping) { /// Prices must be numbers, there is a conversion function that converts strings to int/double, if that fails it turns the value to zero
    if (topping.get_priceL() <= 0) {                             /// So we just have to make sure that the number is not zero or lower
        throw (InvalidToppingPriceException());
    }
    if (topping.get_priceM() <= 0) {
        throw (InvalidToppingPriceException());
    }
    if (topping.get_priceS() <= 0) {
        throw (InvalidToppingPriceException());
    }
    if (topping.get_priceL() < topping.get_priceM() || topping.get_priceM() < topping.get_priceS()) { /// Prices should be Large > Medium > Small
        throw (InvalidToppingPriceException());
    }
    return true;
}
