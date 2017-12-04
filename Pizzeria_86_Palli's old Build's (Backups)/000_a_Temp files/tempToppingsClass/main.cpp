#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Toppings {
    private:
        string t_toppings;
        double t_price;
        bool verbose;
    public:
        Toppings() {
            t_toppings = "";
            t_price = 10.0;
            verbose = true;
        }
        void setVerbose(bool v) {
            verbose = v;
        }
        friend istream& operator >> (istream& in, Toppings& toppings) {
            if (toppings.verbose) {
                cout << "Pick toppings: ";
            }
            in >> ws;
            getline (in, toppings.t_toppings);

            return in;
        }
        friend ostream& operator << (ostream& out, const Toppings& toppings) {

            if (toppings.verbose) {
                cout << "Topping = " << toppings.t_toppings << ", Price = " << toppings.t_price << endl;
            }
            else {
                out << toppings.t_toppings << endl;
                out << toppings.t_price << endl;
            }

            return out;
        }
};

int main()
{
    int i_choice;
    string choice;

    cout << "Hello human, would you like to add a topping to your pizza? ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y" || choice == "Y") {

        cout << "How many toppings do you want? ";
        cin >> i_choice;

        for (int i = 0; i < i_choice; i++) {
            Toppings toppings;
            toppings.setVerbose(true);
            cin >> toppings;
            ofstream fout;
            fout.open("toppings_list.txt", ios::app);
            toppings.setVerbose(false);
            fout << toppings;
            fout.close();
        }
    }

    cout << "Would you like to see the complete list of toppings? ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes" || choice == "YES" || choice == "y" || choice == "Y") {

        Toppings toppings;
        ifstream fin;
        fin.open("toppings_list.txt");

        if (fin.is_open()) {
            int number_of_lines = 0;
            string line;
            ifstream myfile("toppings_list.txt");

            while (getline(myfile, line)) {
                ++number_of_lines;
            }

            for (int i = 0; i < (number_of_lines / 2); i++) {
                toppings.setVerbose(false);
                fin >> toppings;
                toppings.setVerbose(true);
                cout << toppings;
            }
        }
        else {
            cout << "Could not find toppings list" << endl;
        }
    }

    return 0;
}
