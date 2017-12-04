#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AdminToppings {
private:
    string a_toppings;
    double a_price;
    bool verbose;
public:
    AdminToppings() {
        a_toppings = "";
        a_price = 0.0;
        verbose = true;
    }
    void setToppings(string s) {
        a_toppings = s;
    }
    void setPrice(double p) {
        a_price = p;
    }
    void setVerbose(bool v) {
        verbose = v;
    }
    string getToppings() {
        return a_toppings;
    }
    double getPrice() {
        return a_price;
    }
    bool getVerbose() {
        return verbose;
    }

    friend istream& operator >> (istream& in, AdminToppings& admintoppings) {

        if (admintoppings.verbose) {
            cout << "Enter topping: ";
        }
        in >> ws;
        getline (in, admintoppings.a_toppings);

        if (admintoppings.verbose) {
            cout << "Enter price: ";
        }
        in >> admintoppings.a_price;

        return in;
    }

    friend ostream& operator << (ostream& out, const AdminToppings& admintoppings) {

        if (admintoppings.verbose) {
            cout << admintoppings.a_toppings << " (Price: $" << admintoppings.a_price << ")" << endl;
        }
        else {
            out << admintoppings.a_toppings << endl;
            out << admintoppings.a_price << endl;
        }

        return out;
    }

};

int main() /* AdminToppingsUI */
{
    char selection = '\0';

    while (selection != 'q') {

        cout << "Pizzeria_86_Programma (Administrator / Toppings) " << endl;
        cout << "1: Create new Toppings-List (replaces old one)" << endl;
        cout << "2: Add toppings to Toppings-List" << endl;
        cout << "3: Edit current Toppings-List" << endl;
        cout << "4: See current Toppings-List" << endl;
        cout << "5: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') {
            int choice;

            cout << "How many toppings do you want to add? ";
            cin >> choice;

            ofstream tempfout;
            tempfout.open("AdminToppingList.txt");
            tempfout.close();

            for (int i = 0; i < choice; i++) {
                AdminToppings admintoppings;
                admintoppings.setVerbose(true);
                cin >> admintoppings;
                ofstream fout;
                fout.open("AdminToppingList.txt", ios::app);
                admintoppings.setVerbose(false);
                fout << admintoppings;
                fout.close();
            }

        }
        else if (selection == '2') {
            int choice;

            cout << "How many toppings do you want to add? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                AdminToppings admintoppings;
                admintoppings.setVerbose(true);
                cin >> admintoppings;
                ofstream fout;
                fout.open("AdminToppingList.txt", ios::app);
                admintoppings.setVerbose(false);
                fout << admintoppings;
                fout.close();
            }
        }
        else if (selection == '3') {
            cout << "Feature not available (in development)" << endl;
        }
        else if (selection == '4') {
            AdminToppings admintoppings;
            ifstream fin;
            fin.open("AdminToppingList.txt");

            if (fin.is_open()) {
                int number_of_lines = 0;
                string line;
                ifstream myfile("AdminToppingList.txt");

                while (getline(myfile, line)) {
                    ++number_of_lines;
                }

                for (int i = 0; i < (number_of_lines / 2); i++) {
                    admintoppings.setVerbose(false);
                    fin >> admintoppings;
                    admintoppings.setVerbose(true);
                    cout << admintoppings;
                }
        }
        else {
            cout << "Could not find toppings list" << endl;
        }
        }
        else if (selection == '5') {
            selection = 'q';
        }
    }
}
