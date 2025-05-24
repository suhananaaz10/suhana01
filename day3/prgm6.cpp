#include <iostream>
using namespace std;

class shape
{
public:
    virtual void draw() = 0;
};

class Circle : public shape
{
public:
    void draw() override
    {
        cout << "Drawing Circle" << endl;
    }
};

int main()
{
    Circle c;
    c.draw();

    return 0;

}
