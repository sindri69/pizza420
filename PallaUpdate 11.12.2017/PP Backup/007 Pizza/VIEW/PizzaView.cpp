#include "PizzaView.h"
#include "PizzaRead.h" /// This gives us information about the file we're about to view
#include "ConstValues.h"

PizzaView::PizzaView() { }

void PizzaView::viewPizza() {   /// Here we show the PizzaList in an organized way
    PizzaRead p;
    if (p.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (p.get_NumberOfLines() / NUMBEROFVALUESINPIZZA); i++) { /// For number of pizzas in file ...
            string pID = p.get_Line(linecount);
            string pSize = p.get_Line(linecount + 1);
            string pType = p.get_Line(linecount + 2);
            string pTopping = p.get_Line(linecount + 3);
            string pPrice = p.get_Line(linecount + 4);
            string pPayedFor = p.get_Line(linecount + 5);
            string pStatus = p.get_Line(linecount + 6);
            linecount = linecount + NUMBEROFVALUESINPIZZA;

            cout << i+1 << ". (" << pID << ") " << pSize << " ";

            if (pType == "Basic") {
                cout << "Basic Pizza ";
            }
            else if (pType == "Custom") {
                cout << "Custom Pizza with " << pTopping << " ";
            }
            else {
                cout << pType << " ";
            }

            cout << "($" << pPrice << ") ";

            if (pPayedFor == "1") {
                cout << "(Already Payed) ";
            }
            else {
                cout << "(Not Payed For) ";
            }

            if (pStatus == "1") {
                cout << "(Not made)" << endl;
            }
            else if (pStatus == "2") {
                cout << "(Being made)" << endl;
            }
            else if (pStatus == "3") {
                cout << "(Ready)" << endl;
            }
            else if (pStatus == "4") {
                cout << "(Delivered)" << endl;
            }
            else {
                cout << "(PIZZA IS RUINED)" << endl;
            }
        }
    }
    else {
        cout << "The Pizza-List is empty" << endl;
    }
}
