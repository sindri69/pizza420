#include "PizzaMake.h"
#include "PizzaRead.h"

PizzaMake::PizzaMake() { }

void PizzaMake::make_pizza(const Pizza& pizza) {

    if(isValidPizzaID(pizza)) {
        pizza_repo.make_pizza(pizza);
    }
}

bool PizzaMake::isValidPizzaID(const Pizza& pizza) {
    PizzaRead p;
    if (p.check_PizzaIDAlreadyExists(pizza.get_pID())) {
        throw (InvalidPizzaIDAlreadyTakenException());
    }
    return true;
}
