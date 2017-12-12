#include "BasicView.h"
#include "BasicRead.h"

BasicView::BasicView() { }

void BasicView::view_basic() {
    BasicRead br;
    if (br.fileNotEmpty_basic()) {
        cout << "(L = $" << br.get_Line_basic(1) << ") ";
        cout << "(M = $" << br.get_Line_basic(2) << ") ";
        cout << "(S = $" << br.get_Line_basic(3) << ")" << endl;
    }
    else {
        cout << "File is empty" << endl;
    }
}
