#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "Pizza.h"

class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void storePizza(const Pizza& pizza);
        Pizza retrievePizza();

    protected:

    private:
};

#endif // PIZZAREPOSITORY_H
