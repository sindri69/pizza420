#include "ToppingMake.h"
#include "ReadFunctions.h"

ToppingMake::ToppingMake()
{
    //ctor
}

void ToppingMake::make_topping(const Topping& topping) {

    if(isValidToppingName(topping) && isValidToppingPrice(topping)) {
        topping_repo.make_topping(topping);
    }
}

bool ToppingMake::isValidToppingName(const Topping& topping) {

    ReadFunctions fun;
    if (!fun.check_NameIsAvailable_topping(topping.get_name())) {
        throw (InvalidToppingNameException());
    }

    return true;
}

bool ToppingMake::isValidToppingPrice(const Topping & topping) {
    if (topping.get_price() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidToppingPriceException());
    }
    return true;
}
