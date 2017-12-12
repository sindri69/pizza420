#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H

#include "Topping.h"
#include "ToppingRepository.h"
#include <fstream>

class ToppingRepository
{
    public:
        ToppingRepository();
        void make_topping(const Topping& topping);
};

#endif // TOPPINGREPOSITORY_H
