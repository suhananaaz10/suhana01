#include <iostream>
using namespace std;

class Animal
{
public:
    void breathe()
    {
        cout << "Animal breathing..." << endl;
    }
};


class Mamal : public Animal
{
public:
    void feedMilk()
    {
        cout << "Mammal feeding milk to babies." << endl;
    }
};


class Dog : public Mamal
{
public:
    void bark()
    {
        cout << "Dog barking!" << endl;
    }
};

int main()
{
    Dog d;
    d.breathe();
    d.feedMilk();
    d.bark();
    return 0;


}