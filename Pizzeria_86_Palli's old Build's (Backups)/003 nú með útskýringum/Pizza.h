#ifndef PIZZA_H
#define PIZZA_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class Pizza                     /* � .h skr�m eru private gildi skr�� og public functions *declared*, public function eru implementu� � .cpp */
{
    public:
        Pizza();
        virtual ~Pizza();

        void setVerbose(bool v);

        friend istream& operator >> (istream& in, Pizza& pizza);
        friend ostream& operator << (ostream& out, const Pizza& pizza);

    protected:

    private:              /* atm eru bara tv� pizza values; size og type */
        string p_size;
        string p_type;

        bool verbose;     /* Verbose segir til um hvort vi� viljum aukatexta e�a ekki, viljum autatexta � skj�inn, ekki � textafiles */
};

#endif // PIZZA_H
