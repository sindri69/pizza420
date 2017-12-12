#ifndef TYPEVIEW_H
#define TYPEVIEW_H

using namespace std;

class TypeView
{
    public:
        TypeView();

        void view_type();   /// Here we display name and prices for all types
        void view_L_type(); /// Here we display name and price for Large
        void view_M_type(); /// Here we display name and price for Medium
        void view_S_type(); /// Here we display name and price for Small
};

#endif // TYPEVIEW_H
