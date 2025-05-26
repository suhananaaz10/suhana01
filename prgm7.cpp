#include <iostream>
using namespace std;


class Person
{
public:
    void introduce()
    {
        cout << "I am a persom." << endl;
    }
};


class Student : public Person
{
public:
    void study()
    {
        cout << "Studying..." << endl;
    }
};


class Employee : public Person
{
public:
    void work()
    {
        cout << "Working..." << endl;
    }
};


class WorkingStudent : public Student, public Employee
{
public:
    void mange()
    {
        cout << "Managing both work and studies." << endl;
    }
};
  

int main()
{
    WorkingStudent ws;
    ws.Student::introduce();
    ws.Employee::introduce();
    ws.study();
    ws.work();
    ws.mange();
    return 0;
}