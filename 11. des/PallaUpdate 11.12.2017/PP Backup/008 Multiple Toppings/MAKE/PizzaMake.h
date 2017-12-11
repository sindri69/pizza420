#ifndef PIZZAMAKE_H
#define PIZZAMAKE_H

#include "Pizza.h"
#include "PizzaRepository.h"
#include "InvalidPizzaIDAlreadyTakenException.h"

class PizzaMake
{
    public:
        PizzaMake();

        void make_pizza(const Pizza& pizza);

    private:
        PizzaRepository pizza_repo;
        bool isValidPizzaID(const Pizza& pizza);
};

#endif // PIZZAMAKE_H
