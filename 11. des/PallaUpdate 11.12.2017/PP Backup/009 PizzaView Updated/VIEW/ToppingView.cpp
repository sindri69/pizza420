#include "ToppingView.h"
#include "ToppingRead.h" /// This gives us information about the file we're about to view
#include "ConstValues.h"

ToppingView::ToppingView() { }

void ToppingView::viewTopping() {   /// Here we display name and prices for all toppings
    ToppingRead t;
    if (t.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines() / NUMBEROFVALUESINTOPPING); i++) { /// For number of toppings in file ...
            string name = t.get_Line(linecount);
            string priceL = t.get_Line(linecount + 1);
            string priceM = t.get_Line(linecount + 2);
            string priceS = t.get_Line(linecount + 3);
            linecount = linecount + 4;

            cout << i+1 << ". "<< name << " (L = $" << priceL << ") (M = $" << priceM << ") (S = $" << priceS << ")" << endl;
        }
    }
    else {
        cout << "The Toppings-List is empty" << endl;
    }
}
void ToppingView::view_L_Topping() { /// Here we display name and price for Large
    ToppingRead t;
    if (t.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines() / NUMBEROFVALUESINTOPPING); i++) { /// For number of toppings in file ...
            string name = t.get_Line(linecount);
            string price = t.get_Line(linecount + 1);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Toppings-List is empty" << endl;
    }
}
void ToppingView::view_M_Topping() { /// Here we display name and price for Medium
    ToppingRead t;
    if (t.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines() / NUMBEROFVALUESINTOPPING); i++) { /// For number of toppings in file ...
            string name = t.get_Line(linecount);
            string price = t.get_Line(linecount + 2);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Toppings-List is empty" << endl;
    }
}
void ToppingView::view_S_Topping() { /// Here we display name and price for Small
    ToppingRead t;
    if (t.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines() / NUMBEROFVALUESINTOPPING); i++) { /// For number of toppings in file ...
            string name = t.get_Line(linecount);
            string price = t.get_Line(linecount + 3);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Toppings-List is empty" << endl;
    }
}

