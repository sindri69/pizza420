#ifndef TOPPINGVIEW_H
#define TOPPINGVIEW_H

using namespace std;

class ToppingView
{
    public:
        ToppingView();

        void viewTopping();   /// Here we display name and prices for all toppings
        void view_L_Topping(); /// Here we display name and price for Large
        void view_M_Topping(); /// Here we display name and price for Medium
        void view_S_Topping(); /// Here we display name and price for Small
};

#endif // TOPPINGVIEW_H
