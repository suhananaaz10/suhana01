#include <iostream>
using namespace std;
class student
{
public:
    int *marks;
    int size;

    student (int s)
    {
        size = s;
        marks = new int [size];
    }

    student(const student &s)
    {
        size = s.size;
        marks = new int [size];
        for (int i=0; i< size; i++)
        {
            marks[i]=s.marks[i];
        }
    }
    ~student()
    {
        delete[] marks;
    }

    void display()
    {
        for (int i=0; i < size;i++)
        {
            cout << marks[i] << " ";
        }
        cout <<endl;
    }
};

int main()
{
    student s1(3);
    s1.marks[0]-80;
    s1.marks[1]=90;
    s1.marks[2]=85;

    student s2=s1;
    s2.display();

    return 0;
}
