#include "ExtraView.h"
#include "ExtraRead.h" /// This gives us information about the file we're about to view
#include "ConstValues.h"

ExtraView::ExtraView() { }

void ExtraView::viewExtra() {   /// Here we display name and prices for all drinks
    ExtraRead e;
    if (e.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (e.get_NumberOfLines() / NUMBEROFVALUESINEXTRA); i++) { /// For number of extras in file ...
            string name = e.get_Line(linecount);
            string priceL = e.get_Line(linecount + 1);
            string priceM = e.get_Line(linecount + 2);
            string priceS = e.get_Line(linecount + 3);
            linecount = linecount + 4;

            cout << i+1 << ". "<< name << " (L = $" << priceL << ") (M = $" << priceM << ") (S = $" << priceS << ")" << endl;
        }
    }
    else {
        cout << "The Extras-List is empty" << endl;
    }
}
void ExtraView::view_L_Extra() { /// Here we display name and price for Large
    ExtraRead e;
    if (e.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (e.get_NumberOfLines() / NUMBEROFVALUESINEXTRA); i++) { /// For number of extras in file ...
            string name = e.get_Line(linecount);
            string price = e.get_Line(linecount + 1);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Extra-List is empty" << endl;
    }
}
void ExtraView::view_M_Extra() { /// Here we display name and price for Medium
    ExtraRead e;
    if (e.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (e.get_NumberOfLines() / NUMBEROFVALUESINEXTRA); i++) { /// For number of extras in file ...
            string name = e.get_Line(linecount);
            string price = e.get_Line(linecount + 2);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Extra-List is empty" << endl;
    }
}
void ExtraView::view_S_Extra() { /// Here we display name and price for Small
    ExtraRead e;
    if (e.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (e.get_NumberOfLines() / NUMBEROFVALUESINEXTRA); i++) { /// For number of extras in file ...
            string name = e.get_Line(linecount);
            string price = e.get_Line(linecount + 3);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Extra-List is empty" << endl;
    }
}

