#include <iostream>
using namespace std;

class person
{
private:
    string name;
    int age;

public:

    void setData(string n, int a)
    {
        name = n;
        age = a;
    }
    void displaydata()
    {
        cout << "Name: " << name << ", Age: " << age <<  endl;
    }
};
int main()
{
    person p1;
    p1.setData("suhana",19);
    p1.displaydata();

    return 0;
}


