#include "TypeView.h"
#include "ConstValues.h"
#include "TypeRead.h" /// This gives us information about the file we're about to view

TypeView::TypeView() { }

void TypeView::view_type() {   /// Here we display name and prices for all types
    TypeRead t;
    if (t.fileNotEmpty_type()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines_type() / NUMBEROFVALUESINTYPE); i++) { /// For number of types in file ...
            string name = t.get_Line_type(linecount);
            string priceL = t.get_Line_type(linecount + 1);
            string priceM = t.get_Line_type(linecount + 2);
            string priceS = t.get_Line_type(linecount + 3);
            linecount = linecount + 4;

            cout << i+1 << ". "<< name << " (L = $" << priceL << ") (M = $" << priceM << ") (S = $" << priceS << ")" << endl;
        }
    }
    else {
        cout << "The Types-List is empty" << endl;
    }
}
void TypeView::view_L_type() { /// Here we display name and price for Large
    TypeRead t;
    if (t.fileNotEmpty_type()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines_type() / NUMBEROFVALUESINTYPE); i++) { /// For number of types in file ...
            string name = t.get_Line_type(linecount);
            string price = t.get_Line_type(linecount + 1);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Types-List is empty" << endl;
    }
}
void TypeView::view_M_type() { /// Here we display name and price for Medium
    TypeRead t;
    if (t.fileNotEmpty_type()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines_type() / NUMBEROFVALUESINTYPE); i++) { /// For number of types in file ...
            string name = t.get_Line_type(linecount);
            string price = t.get_Line_type(linecount + 2);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Types-List is empty" << endl;
    }
}
void TypeView::view_S_type() { /// Here we display name and price for Small
    TypeRead t;
    if (t.fileNotEmpty_type()) {
        int linecount = 1;
        for (int i = 0; i < (t.get_NumberOfLines_type() / NUMBEROFVALUESINTYPE); i++) { /// For number of types in file ...
            string name = t.get_Line_type(linecount);
            string price = t.get_Line_type(linecount + 3);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Types-List is empty" << endl;
    }
}

