#ifndef DRINKVIEW_H
#define DRINKVIEW_H

using namespace std;

class DrinkView
{
    public:
        DrinkView();

        void viewDrink();    /// Here we display name and prices for all drinks
        void view_L_Drink(); /// Here we display name and price for Large
        void view_M_Drink(); /// Here we display name and price for Medium
        void view_S_Drink(); /// Here we display name and price for Small
};

#endif // DRINKVIEW_H
