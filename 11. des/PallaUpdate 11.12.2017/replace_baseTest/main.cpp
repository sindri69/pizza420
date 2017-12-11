#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class PizzaEdit {
    public:
        void replaceLine(string newline, int oldlinenum) {
            int index = oldlinenum - 1;
            vector <string> v;
            string line;                /// Lines from file
            ifstream fin ("test.txt");
            while (getline(fin,line)) { /// Each line in the file becomes an element in the vector
                v.push_back(line);
            }
            fin.close();

            v.erase(v.begin() + index);
            v.insert(v.begin() + index,newline);

            ofstream fout ("test.txt"); /// Finally we overwrite the old file with the modified vector
            for (unsigned int i = 0; i < v.size(); i++) {
                fout << v[i] << endl;
            }
            fout.close();
        }
};

int main()
{
    PizzaEdit pe;

    pe.replaceLine("FIVE",20);

    return 0;
}
