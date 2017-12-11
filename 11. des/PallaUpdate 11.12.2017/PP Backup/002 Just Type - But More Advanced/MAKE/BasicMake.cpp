#include "BasicMake.h"

BasicMake::BasicMake() { }

void BasicMake::make_basic(const Basic& basic) {
    if(isValidBasicPrice(basic)) {
        basic_repo.make_basic(basic);
    }
}

bool BasicMake::isValidBasicPrice(const Basic & basic) {
    if (basic.get_priceL() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidBasicPriceException());
    }
    if (basic.get_priceM() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidBasicPriceException());
    }
    if (basic.get_priceS() <= 0) {
        cout << "Invalid Price!" << endl;
        throw (InvalidBasicPriceException());
    }
    return true;
}
