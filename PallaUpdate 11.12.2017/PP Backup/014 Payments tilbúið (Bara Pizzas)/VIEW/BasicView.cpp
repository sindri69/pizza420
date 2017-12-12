#include "BasicView.h"
#include "BasicRead.h"

BasicView::BasicView() { }

void BasicView::view_basic() {
    BasicRead br;
    if (br.fileNotEmpty()) {
        cout << "(L = $" << br.get_Line(1) << ") ";
        cout << "(M = $" << br.get_Line(2) << ") ";
        cout << "(S = $" << br.get_Line(3) << ")" << endl;
    }
    else {
        cout << "File is empty" << endl;
    }
}
