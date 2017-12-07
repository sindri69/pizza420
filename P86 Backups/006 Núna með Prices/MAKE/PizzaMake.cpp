#include "PizzaMake.h"

PizzaMake::PizzaMake()
{
    //ctor
}

void PizzaMake::make_pizza(const Pizza& pizza) {

    pizza_repo.make_pizza(pizza);
}
