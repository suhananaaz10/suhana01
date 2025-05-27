#include <iostream>
using namespace std;

class Print
{
public:
    void display(int num)
    {
        cout << "Printing number:" << num << endl;
    }
    void display(string name)
    {
        cout << "printing name:" << name << endl;
    }
};

int main()
{
    Print obj;
    obj.display(10);
    obj.display("Alice");
    return 0;
}