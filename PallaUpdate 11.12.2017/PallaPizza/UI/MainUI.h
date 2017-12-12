#ifndef MAINUI_H
#define MAINUI_H

#include <cstdlib> /// system("CLS");  It cleans our screen, making it more neat !
#include <iostream>
using namespace std;

class MainUI
{
    public:
        MainUI(); /// MainUI just holds the Primary Menus, no logic here

        void start_MainMenu();
        void start_AdminMenu();
        void start_BakingMenu();
        void start_SalesMenu();
};

#endif // MAINUI_H
