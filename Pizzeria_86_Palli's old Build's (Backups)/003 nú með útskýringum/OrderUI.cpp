#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "OrderUI.h"
#include "Pizza.h"
using namespace std;

/* Þetta const value er mjög mikilvæt! */
/* Þegar fleiri values bætast við Pizza.h þurfum við að uppfæra þessa tölu */
/* Annars mun "See list of all Orders" ekki skila öllum listanum! */

const int numberOfValuesInPizzaClass = 2;

OrderUI::OrderUI()
{
    //ctor
}

OrderUI::~OrderUI()
{
    //dtor
}

void OrderUI::start_orderUI() {

    char selection = '\0';

    while (selection != 'q') {

        /* Basic loop */
        /* Velur 1. fyrir að bæta við listann, */
        /* Velur 2. til að sjá allan listan */
        /* Velur 3. til að fara aftur í mainUI */

        cout << "Pizzeria_86_Programma (Orders)" << endl;
        cout << "1: Add Order" << endl;
        cout << "2: See list of all Orders" << endl;
        cout << "3: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') { /*Hér erum við að bæta við PizzaListann */
            int choice;

            cout << "How many pizzas do you wish to add to the list? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Pizza pizza;                             /* Kallað í Pizza.h */
                pizza.setVerbose(true);                  /* Verbose lætur aukatexta fylgja með */
                cin >> pizza;                            /* Bætum við PizzaClassa */
                ofstream fout;                           /* ofstream bætir við texta */
                fout.open("pizza_list.txt", ios::app);   /* opnum pizzalista textfileið, "ios:app" lætur okkur bæta við listann í stað þess að over-write-a hann */
                pizza.setVerbose(false);                 /* Viljum ekki fá aukatexta í fileið */
                fout << pizza;                           /* Prentum listann í skjalið */
                fout.close();                            /* Lokum pizzalista textfileið */
            }
        }
        else if (selection == '2') {                     /* Hér erum við að prenta allan listann */
            Pizza pizza;                                 /* Kallað á Pizza.h */
            ifstream fin;                                /* ifstream les úr texta */
            fin.open("pizza_list.txt");                  /* opnum pizzalista textafileið */

            if (fin.is_open()) {                         /* Hér erum við að check-a hvort pizza-files-ið sé til, ofstream myndi búa það til, en ifstream getur bara lesið úr því */
                int number_of_lines = 0;                 /* Hér byrjar function sem telur fjölda lína í textfileinu */
                std::string line;
                std::ifstream myfile("pizza_list.txt");

                while (std::getline(myfile, line))
                ++number_of_lines;                       /* Hér endar function sem telur fjölda lína í textfileinu */

                for (int i = 0; i < (number_of_lines / numberOfValuesInPizzaClass); i++) { /* Hér deilum við línufjölda við fjölda value-a í classanum til að vita hversu margar pizzur eru í listanum */
                    pizza.setVerbose(false);             /* Lesum engan aukatexta úr fileinu */
                    fin >> pizza;
                    pizza.setVerbose(true);              /* Viljum fá aukatexta á skjáinn */
                    cout << pizza;
                }
            }
            else {
                cout << "Could not find pizza list" << endl; /* Ef skjalið er ekki til þá kemur þetta fram */
            }
        }
        else if (selection == '3') { /* Þetta endar loopið og sendir okkur aftur í mainUI */
            selection = 'q';
        }
    }
}
