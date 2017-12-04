#ifndef PIZZA_H
#define PIZZA_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class Pizza                     /* í .h skrám eru private gildi skráð og public functions *declared*, public function eru implementuð í .cpp */
{
    public:
        Pizza();
        virtual ~Pizza();

        void setVerbose(bool v);

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);

    protected:

    private:              /* atm eru bara tvö pizza values; size og type */
        string p_size;
        string p_type;

        bool verbose;     /* Verbose segir til um hvort við viljum aukatexta eða ekki, viljum autatexta á skjáinn, ekki í textafiles */
};

#endif // PIZZA_H
