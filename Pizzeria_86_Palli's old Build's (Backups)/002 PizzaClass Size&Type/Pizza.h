#ifndef PIZZA_H
#define PIZZA_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        void setVerbose(bool v);

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);

    protected:

    private:
        string p_size;
        string p_type;
        bool verbose;
};

#endif // PIZZA_H
