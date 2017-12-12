#ifndef EXTRAVIEW_H
#define EXTRAVIEW_H

using namespace std;

class ExtraView
{
    public:
        ExtraView();

        void viewExtra();    /// Here we display name and prices for all extras
        void view_L_Extra(); /// Here we display name and price for Large
        void view_M_Extra(); /// Here we display name and price for Medium
        void view_S_Extra(); /// Here we display name and price for Small
};

#endif // EXTRAVIEW_H
