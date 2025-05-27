#include <iostream>
using namespace std;

class Item
{
private:
    int quantity;
    float price;

public:
    Item(int q = 0, float p = 0.0f) : quantity(q), price(p) {}

    Item operator+(const Item &other)
    {
        return Item(quantity + other.quantity, price + other.price);
    }

    bool operator==(const Item &other)
    {
        return (quantity == other.quantity && price == other.price);
    }

    friend ostream &operator<<(ostream &os, const Item &item)
    {
        os << "Item -> Quantity:" << item.quantity << ", Price: $" << item.price;
        return os;
    }
};

int main()
{
    Item item1(10, 250.50);
    Item item2(5, 100.25);
    Item item3(10, 250.50);

    Item toatl = item1 + item2;

    cout << toatl << endl;

    if (item1 == item3)
        cout << "item1 and item3 are same in quantity and price." << endl;
    else
        cout << "item1 and item3 are different." << endl;

    return 0;

}