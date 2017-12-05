#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Types
{
    public:
        Types();
        virtual ~Types();

        /* Functions that set and get the private values */
        void setTypes(string s);
        void setPrice(double p);
        void setVerbose(bool v);
        string getTypes();
        double getPrice();
        bool getVerbose();

        /* Functions that add to and read from TypesList */
        friend istream& operator >> (istream& in, Types& types);
        friend ostream& operator << (ostream& out, const Types& types);

    protected:

    private:
        string a_types;
        double a_price;
        bool verbose;
};

#endif // TYPES_H
