#include <iostream>
using namespace std;

class Superhero
{
    public:
        void getName(string name);
        void getSuperpower(char superpower);
        void getAge(int age);
    private:
        string name;
        char superpower;
        int age;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


void Superhero::getName(name)
{
    this->name = name;
}

void Superhero::getSuperpower(superpower)
{
    this->superpower = superpower;
}

void Superhero::getAge(age)
{
    this->age = age;
}
