#ifndef EXTRAS_H
#define EXTRAS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Extras
{
    public:
        Extras();
        virtual ~Extras();

        /* Functions that either get or set the private values */
        void setExtras(string s);
        void setPrice(double p);
        void setVerbose(bool v);
        string getExtras();
        double getPrice();
        bool getVerbose();

        /* Functions used to read from and add to ExtrasList */
        friend istream& operator >> (istream& in, Extras& extras);
        friend ostream& operator << (ostream& out, const Extras& extras);

    protected:

    private:
        string a_extras;
        double a_price;
        bool verbose;
};

#endif // EXTRAS_H
