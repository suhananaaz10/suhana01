#include <iostream>
using namespace std;

class Car 
{
public:
    string model;
    Car(string model)
    {
        this->model = model;
    }
    void show()
    {
        cout << "Car model: " << this->model << endl;
    }
};

int main()
{
    Car c("Toyata");
    c.show();
    return 0;
}