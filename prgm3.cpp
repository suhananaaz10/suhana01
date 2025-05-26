#include <iostream>
using namespace std;

class Bus
{
public:
    void start()
    {
        cout << "bus has started." << endl;
    }
};

class Vehicle : public Bus
{
public:
    void drive()
    {
    cout << " Bus is driving!" << endl;
    }
};

int main()
{
    Vehicle myBus;
    myBus.start();
    myBus.drive();
    return 0;
}
