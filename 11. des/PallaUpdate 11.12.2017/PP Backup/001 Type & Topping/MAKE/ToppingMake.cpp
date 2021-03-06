#include "ToppingMake.h"

ToppingMake::ToppingMake() { }

void ToppingMake::make_topping(const Topping& topping) {

    if(isValidToppingName(topping) && isValidToppingPrice(topping)) {
        topping_repo.make_topping(topping);
    }
}

bool ToppingMake::isValidToppingName(const Topping& topping) {
    if (false) {
        throw (InvalidToppingNameException());
    }
    return true;
}

bool ToppingMake::isValidToppingPrice(const Topping & topping) {
    if (topping.get_priceL() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidToppingPriceException());
    }
    if (topping.get_priceM() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidToppingPriceException());
    }
    if (topping.get_priceS() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidToppingPriceException());
    }
    return true;
}
