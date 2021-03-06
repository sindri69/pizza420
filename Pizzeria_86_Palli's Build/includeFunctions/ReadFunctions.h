#ifndef READFUNCTIONS_H
#define READFUNCTIONS_H
#include <string>
using namespace std;

class ReadFunctions /* Functions that read from and/or get values from text files */
{
    public:
        ReadFunctions();
        virtual ~ReadFunctions();

        /* Check if the file exists */
        bool fileExists_PizzaList();
        bool fileExists_TypesList();
        bool fileExists_ToppingsList();
        bool fileExists_DrinksList();
        bool fileExists_ExtrasList();

        /* Check if the file exists and if it's empty */
        bool fileExists_AndNotEmpty_PizzaList();
        bool fileExists_AndNotEmpty_TypesList();
        bool fileExists_AndNotEmpty_ToppingsList();
        bool fileExists_AndNotEmpty_DrinksList();
        bool fileExists_AndNotEmpty_ExtrasList();

        /* Check if any line in the file matches userInput */
        bool nameSake_PizzaList(string line);
        bool nameSake_TypesList(string line);
        bool nameSake_ToppingsList(string line);
        bool nameSake_DrinksList(string line);
        bool nameSake_ExtrasList(string line);

        /* Check if string matches line in text-file */
        bool lineMatches_PizzaList(string line, int linenum);
        bool lineMatches_TypesList(string line, int linenum);
        bool lineMatches_ToppingsList(string line, int linenum);
        bool lineMatches_DrinksList(string line, int linenum);
        bool lineMatches_ExtrasList(string line, int linenum);

        /* Count the number of lines in the file */
        int get_NumberOfLines_PizzaList();
        int get_NumberOfLines_TypesList();
        int get_NumberOfLines_ToppingsList();
        int get_NumberOfLines_DrinksList();
        int get_NumberOfLines_ExtrasList();

        /* Get line from file */
        string get_Line_PizzaList(int linenum);
        string get_Line_TypesList(int linenum);
        string get_Line_ToppingsList(int linenum);
        string get_Line_DrinksList(int linenum);
        string get_Line_ExtrasList(int linenum);

        /* Read all the lines in the file, without changing the format */
        void read_PizzaList();
        void read_TypesList();
        void read_ToppingsList();
        void read_DrinksList();
        void read_ExtrasList();

        /* Read all the lines in the file, in a neat format (fancy) */
        void read_PizzaListFancy();

    protected:

    private:
};

#endif // READFUNCTIONS_H
