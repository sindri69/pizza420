#ifndef READFUNCTIONS_H
#define READFUNCTIONS_H
#include <string>
using namespace std;

class ReadFunctions /// Functions involving files, the last word in the function-name is the file being used
{
    public:
        ReadFunctions();


        /// Here we read all the lines in the file
        void read_raw_basic();
        void read_raw_pizza();
        void read_raw_type();
        void read_raw_topping();

        /// Here we read from the files in an organized manner
        void read_fancy_basic();
        void read_fancy_pizza();
        void read_fancy_type();
        void read_fancy_topping();

        /// Here we delete all the lines in the file
        void delete_basic();
        void delete_pizza();
        void delete_type();
        void delete_topping();

        /// Here we get a specific line from the file
        string get_Line_basic(int linenumber);
        string get_Line_pizza(int linenumber);
        string get_Line_type(int linenumber);
        string get_Line_topping(int linenumber);

        /// Here we count the number of lines in the file
        int get_NumberOfLines_basic();
        int get_NumberOfLines_pizza();
        int get_NumberOfLines_type();
        int get_NumberOfLines_topping();

        /// Here we check if the file is empty
        bool fileNotEmpty_basic();
        bool fileNotEmpty_pizza();
        bool fileNotEmpty_type();
        bool fileNotEmpty_topping();

        /// Here we check if a specific line matches a line in the file
        bool check_LineMatches_basic(string line, int linenumber);
        bool check_LineMatches_pizza(string line, int linenumber);
        bool check_LineMatches_type(string line, int linenumber);
        bool check_LineMatches_topping(string line, int linenumber);

        /// Here we check if a type/topping etc. is already taken                     <- Used when Administrator creates new types/toppings
        bool check_NameIsAvailable_type(string name);
        bool check_NameIsAvailable_topping(string name);

        /// Here we see if a type/topping exists (similar to "NameIsAvailable")       <- Used when User picks types/toppings
        bool check_TypeExists_type(string name);
        bool check_ToppingExists_topping(string name);

    private:
};

#endif // READFUNCTIONS_H
