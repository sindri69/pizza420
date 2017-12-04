#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool is_it_integer = false;
    int LegitInput;
    string userInput;

    while (is_it_integer == false) {

        cout << "Write an integer between 1 and 9 ";
        cin >> userInput;

        if (userInput == "1") {
            LegitInput = 1;
            is_it_integer = true;
        }
        else if (userInput == "2") {
            LegitInput = 2;
            is_it_integer = true;
        }
        else if (userInput == "3") {
            LegitInput = 3;
            is_it_integer = true;
        }
        else if (userInput == "4") {
            LegitInput = 4;
            is_it_integer = true;
        }
        else if (userInput == "5") {
            LegitInput = 5;
            is_it_integer = true;
        }
        else if (userInput == "6") {
            LegitInput = 6;
            is_it_integer = true;
        }
        else if (userInput == "7") {
            LegitInput = 7;
            is_it_integer = true;
        }
        else if (userInput == "8") {
            LegitInput = 8;
            is_it_integer = true;
        }
        else if (userInput == "9") {
            LegitInput = 9;
            is_it_integer = true;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    cout << "You typed the number " << LegitInput << endl;

    return 0;
}
