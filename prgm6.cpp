#include <iostream>
using namespace std;

 class Shape
 {
public:
    void setColor(string c)
    {
        cout << "String color:" << c << endl;
    }
 };


 class Circle : public Shape 
 {
public:
    void drawCircle()
    {
        cout << "Drwaing Circle." << endl;
    }
 };

 class Rectangle : public Shape
 {
public:
    void drawRectangle()
    {
        cout << "Drawing Rectangle." << endl;
    }
 };

 int main()
 {
    Circle c;
    Rectangle r;
    c.setColor("pink");
    c.drawCircle();
    r.setColor("blue");
    r.drawRectangle();
    return 0;
 }