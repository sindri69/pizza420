#ifndef PIZZAMAKE_H
#define PIZZAMAKE_H

#include "Pizza.h"
#include "PizzaRepository.h"

class PizzaMake
{
    public:
        PizzaMake();

        void make_pizza(const Pizza& pizza);

    private:
        PizzaRepository pizza_repo;
};

#endif // PIZZAMAKE_H
