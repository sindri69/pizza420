#include <iostream>
#include <fstream>
#include "MainUI.h"
#include "OrderUI.h"
#include "Pizza.h"
using namespace std;

/* �etta const value er mj�g mikilv�t! */
/* �egar fleiri values b�tast vi� Pizza.h �urfum vi� a� uppf�ra �essa t�lu */
/* Annars mun "See list of all Orders" ekki skila �llum listanum! */

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
        /* Velur 1. fyrir a� b�ta vi� listann, */
        /* Velur 2. til a� sj� allan listan */
        /* Velur 3. til a� fara aftur � mainUI */

        cout << "Pizzeria_86_Programma (Orders)" << endl;
        cout << "1: Add Order" << endl;
        cout << "2: See list of all Orders" << endl;
        cout << "3: Return to Main" << endl;

        cin >> selection;

        if (selection == '1') { /*H�r erum vi� a� b�ta vi� PizzaListann */
            int choice;

            cout << "How many pizzas do you wish to add to the list? ";
            cin >> choice;

            for (int i = 0; i < choice; i++) {
                Pizza pizza;                             /* Kalla� � Pizza.h */
                pizza.setVerbose(true);                  /* Verbose l�tur aukatexta fylgja me� */
                cin >> pizza;                            /* B�tum vi� PizzaClassa */
                ofstream fout;                           /* ofstream b�tir vi� texta */
                fout.open("pizza_list.txt", ios::app);   /* opnum pizzalista textfilei�, "ios:app" l�tur okkur b�ta vi� listann � sta� �ess a� over-write-a hann */
                pizza.setVerbose(false);                 /* Viljum ekki f� aukatexta � filei� */
                fout << pizza;                           /* Prentum listann � skjali� */
                fout.close();                            /* Lokum pizzalista textfilei� */
            }
        }
        else if (selection == '2') {                     /* H�r erum vi� a� prenta allan listann */
            Pizza pizza;                                 /* Kalla� � Pizza.h */
            ifstream fin;                                /* ifstream les �r texta */
            fin.open("pizza_list.txt");                  /* opnum pizzalista textafilei� */

            if (fin.is_open()) {                         /* H�r erum vi� a� check-a hvort pizza-files-i� s� til, ofstream myndi b�a �a� til, en ifstream getur bara lesi� �r �v� */
                int number_of_lines = 0;                 /* H�r byrjar function sem telur fj�lda l�na � textfileinu */
                std::string line;
                std::ifstream myfile("pizza_list.txt");

                while (std::getline(myfile, line))
                ++number_of_lines;                       /* H�r endar function sem telur fj�lda l�na � textfileinu */

                for (int i = 0; i < (number_of_lines / numberOfValuesInPizzaClass); i++) { /* H�r deilum vi� l�nufj�lda vi� fj�lda value-a � classanum til a� vita hversu margar pizzur eru � listanum */
                    pizza.setVerbose(false);             /* Lesum engan aukatexta �r fileinu */
                    fin >> pizza;
                    pizza.setVerbose(true);              /* Viljum f� aukatexta � skj�inn */
                    cout << pizza;
                }
            }
            else {
                cout << "Could not find pizza list" << endl; /* Ef skjali� er ekki til �� kemur �etta fram */
            }
        }
        else if (selection == '3') { /* �etta endar loopi� og sendir okkur aftur � mainUI */
            selection = 'q';
        }
    }
}
