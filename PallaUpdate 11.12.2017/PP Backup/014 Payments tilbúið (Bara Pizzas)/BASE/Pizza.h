#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <iostream>
using namespace std;

class Pizza
{
    public:
        Pizza(string pID, string psize, string ptype, string ptopping, double pprice, bool ppayedfor, int pstatus);

        string get_pID() const;
        string get_psize() const;
        string get_ptype() const;
        string get_ptopping() const;
        double get_pprice() const;
        bool get_ppayedfor() const;
        int get_pstatus() const;

        friend ostream& operator << (ostream& out, const Pizza& pizza);

    private:
        string pID;
        string psize;
        string ptype;
        string ptopping;
        double pprice;
        bool ppayedfor;
        int pstatus;
};

#endif // PIZZA_H
