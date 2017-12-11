#ifndef TYPEVIEW_H
#define TYPEVIEW_H

using namespace std;

class TypeView
{
    public:
        TypeView();

        void viewType();   /// Here we display name and prices for all types
        void view_L_Type(); /// Here we display name and price for Large
        void view_M_Type(); /// Here we display name and price for Medium
        void view_S_Type(); /// Here we display name and price for Small
};

#endif // TYPEVIEW_H
