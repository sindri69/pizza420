#ifndef READFUNCTIONS_H
#define READFUNCTIONS_H
#include <string>
using namespace std;

class ReadFunctions /// Functions involving files, the last word in the function-name is the file being used
{
    public:
        ReadFunctions();

        /// Here we read all the lines in the file
        void read_raw_type();
        void read_raw_topping();

        /// Here we read from the files in an organized manner
        void read_fancy_type();
        void read_fancy_topping();

        /// Here we delete all the lines in the file
        void delete_type();
        void delete_topping();

        /// Here we get a specific line from the file
        string get_Line_type(int linenumber);
        string get_Line_topping(int linenumber);

        /// Here we count the number of lines in the file
        int get_NumberOfLines_type();
        int get_NumberOfLines_topping();

        /// Here we check if the file is empty
        bool fileNotEmpty_type();
        bool fileNotEmpty_topping();

        /// Here we check if a specific line matches a line in the file
        bool check_LineMatches_type(string line, int linenumber);
        bool check_LineMatches_topping(string line, int linenumber);

        /// Here we check if a type/topping etc. is already taken
        bool check_NameIsAvailable_type(string name);
        bool check_NameIsAvailable_topping(string name);

    private:
};

#endif // READFUNCTIONS_H
