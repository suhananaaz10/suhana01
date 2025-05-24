#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int age;
    int usn;
    string clg;
    student(string n, int a, int b, string m)
    {
        name = n;
        age = a;
        usn = b;
        clg = m;
        cout << "Name:" << name <<",Age:" << age << ",Usn:" << usn << ",Clg" << clg << endl;
    }
};
int main()
{
    student s1("suhana", 21,24087,"City engineering clg");
    return 0;
}