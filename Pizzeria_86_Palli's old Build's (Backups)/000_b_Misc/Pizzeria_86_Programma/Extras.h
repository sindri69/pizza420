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

        void setExtras(string s);
        void setPrice(double p);
        void setVerbose(bool v);
        string getExtras();
        double getPrice();
        bool getVerbose();

        friend istream& operator >> (istream& in, Extras& extras);
        friend ostream& operator << (ostream& out, const Extras& extras);

    protected:

    private:
        string a_extras;
        double a_price;
        bool verbose;
};

#endif // EXTRAS_H
