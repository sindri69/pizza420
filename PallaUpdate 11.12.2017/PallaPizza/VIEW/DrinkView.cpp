#include "DrinkView.h"
#include "DrinkRead.h" /// This gives us information about the file we're about to view
#include "ConstValues.h"

DrinkView::DrinkView() { }

void DrinkView::viewDrink() {   /// Here we display name and prices for all drinks
    DrinkRead d;
    if (d.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (d.get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// For number of drinks in file ...
            string name = d.get_Line(linecount);
            string priceL = d.get_Line(linecount + 1);
            string priceM = d.get_Line(linecount + 2);
            string priceS = d.get_Line(linecount + 3);
            linecount = linecount + 4;

            cout << i+1 << ". "<< name << " (L = $" << priceL << ") (M = $" << priceM << ") (S = $" << priceS << ")" << endl;
        }
    }
    else {
        cout << "The Drinks-List is empty" << endl;
    }
}
void DrinkView::view_L_Drink() { /// Here we display name and price for Large
    DrinkRead d;
    if (d.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (d.get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// For number of drinks in file ...
            string name = d.get_Line(linecount);
            string price = d.get_Line(linecount + 1);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Drink-List is empty" << endl;
    }
}
void DrinkView::view_M_Drink() { /// Here we display name and price for Medium
    DrinkRead d;
    if (d.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (d.get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// For number of drinks in file ...
            string name = d.get_Line(linecount);
            string price = d.get_Line(linecount + 2);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Drink-List is empty" << endl;
    }
}
void DrinkView::view_S_Drink() { /// Here we display name and price for Small
    DrinkRead d;
    if (d.fileNotEmpty()) {
        int linecount = 1;
        for (int i = 0; i < (d.get_NumberOfLines() / NUMBEROFVALUESINDRINK); i++) { /// For number of drinks in file ...
            string name = d.get_Line(linecount);
            string price = d.get_Line(linecount + 3);
            linecount = linecount + 4;

            cout << name << " ($" << price << ")" << endl;
        }
    }
    else {
        cout << "The Drink-List is empty" << endl;
    }
}

