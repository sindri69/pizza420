#include "ExtraMake.h"
#include "ExtraRead.h"
#include "UserInputUI.h"

ExtraMake::ExtraMake() { }

void ExtraMake::make_extra(const Extra& extra) {

    if(isValidExtraName(extra) && isValidExtraPrice(extra)) {
        extra_repo.make_extra(extra);
    }
}

bool ExtraMake::isValidExtraName(const Extra& extra) {
    UserInputUI ui;
    bool hasAlpha = false;
    string name = extra.get_name();
    for (unsigned int i = 0; i < name.size(); i++) { /// Here we're making sure that the name has at least one character that's not a number
        if (isalpha(name[i])) {
            hasAlpha = true;
            break;
        }
    }
    if (!hasAlpha) {
        throw (InvalidExtraNameNoAlphaException());
    }
    ExtraRead e;
    if (e.check_ExtraAlreadyExists(name)) {
        throw (InvalidExtraNameAlreadyTakenException());
    }
    return true;
}

bool ExtraMake::isValidExtraPrice(const Extra & extra) { /// Prices must be numbers, there is a conversion function that converts strings to int/double, if that fails it turns the value to zero
    if (extra.get_priceL() <= 0) {                       /// So we just have to make sure that the number is not zero or lower
        throw (InvalidExtraPriceException());
    }
    if (extra.get_priceM() <= 0) {
        throw (InvalidExtraPriceException());
    }
    if (extra.get_priceS() <= 0) {
        throw (InvalidExtraPriceException());
    }
    if (extra.get_priceL() < extra.get_priceM() || extra.get_priceM() < extra.get_priceS()) { /// Prices should be Large > Medium > Small
        throw (InvalidExtraPriceException());
    }
    return true;
}

