#include "PizzaMake.h"
#include "PizzaRead.h"

PizzaMake::PizzaMake() { }

void PizzaMake::make_pizza(const Pizza& pizza) {

    pizza_repo.make_pizza(pizza);

}

