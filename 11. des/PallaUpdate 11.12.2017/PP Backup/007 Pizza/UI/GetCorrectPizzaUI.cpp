#include "GetCorrectPizzaUI.h"
#include "ConstValues.h"
#include "BasicRead.h"
#include "PizzaRead.h"
#include "TypeRead.h"
#include "TypeView.h"
#include "ToppingRead.h"
#include "ToppingView.h"
#include "UserInputUI.h"

GetCorrectPizzaUI::GetCorrectPizzaUI() { }

string GetCorrectPizzaUI::getCorrectID() {
    UserInputUI ui;
    PizzaRead pr;

    bool unusedID = false;
    string pizzaID_pre = "pID";
    string pizzaID;
    int pizzaIDnum = 1;

    while (!unusedID) {
        pizzaID = pizzaID_pre + ui.convert_IntegerToString(pizzaIDnum);
        if (pr.check_PizzaIDAlreadyExists(pizzaID)) {
            pizzaIDnum++;
        }
        else {
            unusedID = true;
        }
    }
    return pizzaID;
}
string GetCorrectPizzaUI::getCorrectSize() {
    UserInputUI ui;
    cout << endl;
    string answer = ui.getAnswer("Choose size (L = Large / M = Medium / S = Small)","l","large","m","medium","s","small");
    if (answer == "l" || answer == "large") {
        return "Large";
    }
    else if (answer == "m" || answer == "medium") {
        return "Medium";
    }
    else {
        return "Small";
    }
}
string GetCorrectPizzaUI::getCorrectType() {
    TypeRead tyr;
    TypeView tyv;
    ToppingRead tor;
    UserInputUI ui;
    if (tyr.fileNotEmpty() && tor.fileNotEmpty()) { /// If the Types-List and Toppings-List are both available we can offer Basic, Custom and Menu
        cout << endl;
        string type = ui.getAnswer("Choose type (B = Basic / C = Custom (choose own toppings) / M = Pick from Menu)","b","basic","c","custom","m","menu");
        if (type == "b" || type == "basic") {
            return "Basic";
        }
        if (type == "c" || type == "custom") {
            return "Custom";
        }
    }
    else if (tor.fileNotEmpty()) { /// If the Toppings-List is available then we can offer Basic and Custom
        string type = ui.getAnswer("Choose type (B = Basic / C = Custom (choose own toppings))","b","basic","c","custom");
        if (type == "b" || type == "basic") {
            return "Basic";
        }
        return "Custom";
    }
    else if (tyr.fileNotEmpty()) { /// If the Types-List is available then we can offer Basic and Menu
        string type = ui.getAnswer("choose type (B = Basic / M = Pick from Menu):","b","basic","m","menu");
        if (type == "b" || type == "basic") {
            return "Basic";
        }
    }
    else {
        return "Basic"; /// If the Types-List and Toppings-List are both unavailable then we set the Type to "Basic"
    }
    cout << endl;
    while (true) { /// If the user wants to pick a pizza from the menu then we print out the list of valid Types and only accept input which matches pizza from the Types-List
        cout << "List of Pizza-Types:" << endl;
        tyv.viewType();
        cout << endl;
        string answer = ui.getAnswer("Which Pizza-Type would you like?");
        if (ui.answerIsInteger(answer)) {
            int typenum = ui.convert_StringToInteger(answer);
            if ( typenum <= 0 || typenum > (tyr.get_NumberOfLines() / NUMBEROFVALUESINTYPE) ) { /// If the answer is a number, we try to match that number to the ones on the list
                cout << "That number does not match the ones on the list" << endl << endl;
            }
            else {
                return tyr.get_Line( (typenum * NUMBEROFVALUESINTYPE) - NUMBEROFVALUESINTYPE + 1 ); /// If we want type 1 we take line 1, If we want type 2  we take line 5 ... etc
                cout << endl;
            }
        }
        else {
            if (tyr.check_TypeAlreadyExists(answer)) { /// If the answer is not a number we try to match it to the names on the list
                return answer;
            }
            else {
                cout << "That type is not on the list" << endl << endl;
            }
        }
    }
}
string GetCorrectPizzaUI::getCorrectTopping(string ptype) {
    ToppingRead tor;
    ToppingView tov;
    UserInputUI ui;
    if (ptype == "Custom") {
        cout << endl;
        while (true) {
            cout << "List of Pizza-Toppings:" << endl;
            tov.viewTopping();
            cout << endl;
            string answer = ui.getAnswer("Which Pizza-Topping would you like?");
            if (ui.answerIsInteger(answer)) {
                int toppingnum = ui.convert_StringToInteger(answer);
                if ( toppingnum <= 0 || toppingnum > (tor.get_NumberOfLines() / NUMBEROFVALUESINTOPPING) ) { /// If the answer is a number, we try to match that number to the ones on the list
                    cout << "That number does not match the ones on the list" << endl << endl;
                }
                else {
                    return tor.get_Line( (toppingnum * NUMBEROFVALUESINTOPPING) - NUMBEROFVALUESINTOPPING + 1 ); /// If we want topping 1 we take line 1, If we want topping 2  we take line 5 ... etc
                    cout << endl;
                }
            }
            else {
                if (tor.check_ToppingAlreadyExists(answer)) { /// If the answer is not a number we try to match it to the names on the list
                    return answer;
                }
                else {
                    cout << "That topping is not on the list" << endl << endl;
                }
            }
        }
    }
    return ""; /// If the Pizza-Type is not Custom, then the user does not pick his own toppings
}
double GetCorrectPizzaUI::getCorrectPrice(string psize, string ptype, string ptopping) {
    BasicRead br;
    TypeRead tyr;
    ToppingRead tor;
    UserInputUI ui;
    string price;
    if (ptype == "Basic") { /// If the pizza is a Basic-type then we get the price from the basic text file
        if (br.fileNotEmpty()) {
            if (psize == "Large") {
                price = br.get_Line(1);
            }
            else if (psize == "Medium") {
                price = br.get_Line(2);
            }
            else {
                price = br.get_Line(3);
            }
        }
        else {
            return 0; /// Unless it's empty, then we just return zero ... YAY Free Pizza :D
        }
    }
    else if (ptype == "Custom") { /// If the pizza is a Custom-type then we get the price from the toppings text file
        int linecount = 0;
        bool lineMatches = false;
        for (int i = 0; i < tor.get_NumberOfLines(); i++) { /// We loop out way to the line where the topping is
            linecount ++;
            if (tor.check_LineMatches(ptopping,linecount)) {
                lineMatches = true;
                break;
            }
        }
        if (lineMatches) { /// Once we have found the correct line we can get the prices from the 3 lines bellow it
            if (psize == "Large") {
                price = tor.get_Line(linecount + 1);
            }
            else if (psize == "Medium") {
                price = tor.get_Line(linecount + 2);
            }
            else {
                price = tor.get_Line(linecount + 3);
            }
        }
        else {
            cout << "Error getting Price of Topping" << endl;
            return 0;
        }
    }
    else { /// If the type is not Basic or Custom it must be from the Types-List !
        int linecount = 0;
        bool lineMatches = false;
        for (int i = 0; i < tyr.get_NumberOfLines(); i++) { /// We loop out way to the line where the type is
            linecount ++;
            if (tyr.check_LineMatches(ptype,linecount)) {
                lineMatches = true;
                break;
            }
        }
        if (lineMatches) { /// Once we have found the correct line we can get the prices from the 3 lines bellow it
            if (psize == "Large") {
                price = tyr.get_Line(linecount + 1);
            }
            else if (psize == "Medium") {
                price = tyr.get_Line(linecount + 2);
            }
            else {
                price = tyr.get_Line(linecount + 3);
            }
        }
        else {
            cout << "Error" << endl;
            return 0;
        }
    }
    double legitprice = ui.convert_StringToDouble(price);

    return legitprice;
}
