#include "DrinkMake.h"
#include "DrinkRead.h"
#include "UserInputUI.h"

DrinkMake::DrinkMake() { }

void DrinkMake::make_drink(const Drink& drink) {

    if(isValidDrinkName(drink) && isValidDrinkPrice(drink)) {
        drink_repo.make_drink(drink);
    }
}

bool DrinkMake::isValidDrinkName(const Drink& drink) {
    UserInputUI ui;
    bool hasAlpha = false;
    string name = drink.get_name();
    for (unsigned int i = 0; i < name.size(); i++) { /// Here we're making sure that the name has at least one character that's not a number
        if (isalpha(name[i])) {
            hasAlpha = true;
            break;
        }
    }
    if (!hasAlpha) {
        throw (InvalidDrinkNameNoAlphaException());
    }
    DrinkRead d;
    if (d.check_DrinkAlreadyExists(name)) {
        throw (InvalidDrinkNameAlreadyTakenException());
    }
    return true;
}

bool DrinkMake::isValidDrinkPrice(const Drink & drink) { /// Prices must be numbers, there is a conversion function that converts strings to int/double, if that fails it turns the value to zero
    if (drink.get_priceL() <= 0) {                       /// So we just have to make sure that the number is not zero or lower
        throw (InvalidDrinkPriceException());
    }
    if (drink.get_priceM() <= 0) {
        throw (InvalidDrinkPriceException());
    }
    if (drink.get_priceS() <= 0) {
        throw (InvalidDrinkPriceException());
    }
    if (drink.get_priceL() < drink.get_priceM() || drink.get_priceM() < drink.get_priceS()) { /// Prices should be Large > Medium > Small
        throw (InvalidDrinkPriceException());
    }
    return true;
}

