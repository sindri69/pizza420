#ifndef DRINKREPOSITORY_H
#define DRINKREPOSITORY_H

#include "Drink.h"
#include "DrinkRepository.h"
#include <fstream>

class DrinkRepository
{
    public:
        DrinkRepository();
        void make_drink(const Drink& drink);
};

#endif // DRINKREPOSITORY_H
