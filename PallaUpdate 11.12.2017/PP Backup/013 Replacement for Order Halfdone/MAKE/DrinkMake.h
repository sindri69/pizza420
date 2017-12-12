#ifndef DRINKMAKE_H
#define DRINKMAKE_H

#include "Drink.h"
#include "DrinkRepository.h"
#include "InvalidDrinkNameNoAlphaException.h"
#include "InvalidDrinkNameAlreadyTakenException.h"
#include "InvalidDrinkPriceException.h"

class DrinkMake
{
    public:
        DrinkMake();

        void make_drink(const Drink& drink);

    private:
        DrinkRepository drink_repo;
        bool isValidDrinkName(const Drink& drink);
        bool isValidDrinkPrice(const Drink& drink);
};

#endif // DRINKMAKE_H
