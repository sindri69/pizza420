#ifndef EXTRAUI_H
#define EXTRAUI_H

#include "Extra.h"
#include "ExtraMake.h"

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
using namespace std;

class ExtraUI
{
    public:
        ExtraUI();
        void start_ExtrasMenu();

    private:
        Extra create_extra();
        ExtraMake makeextra;
};

#endif // EXTRAUI_H
