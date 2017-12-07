#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include "Pizza.h"
#include "PizzaRepository.h"
#include <fstream>

class PizzaRepository
{
    public:
        PizzaRepository();
        void make_pizza(const Pizza& pizza);

    private:
};

#endif // PIZZAREPOSITORY_H
