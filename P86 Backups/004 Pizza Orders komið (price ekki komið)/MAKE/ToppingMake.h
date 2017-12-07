#ifndef TOPPINGMAKE_H
#define TOPPINGMAKE_H

#include "Topping.h"
#include "ToppingRepository.h"
#include "InvalidToppingNameException.h"
#include "InvalidToppingPriceException.h"

class ToppingMake
{
    public:
        ToppingMake();

        void make_topping(const Topping& topping);

    private:
        ToppingRepository topping_repo;
        bool isValidToppingName(const Topping& topping);
        bool isValidToppingPrice(const Topping& topping);
};

#endif // TOPPINGMAKE_H
