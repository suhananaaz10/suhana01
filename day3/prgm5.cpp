#include <iostream>
using namespace std;

class product
{
private:
    int quantity;
    float pricePerItem;
    

public:

    void setProduct(int q, float price)
    {
        if (q > 0 && price > 0)
        {
            quantity = q;
            pricePerItem = price;
        }
        else
        {
            cout << "Invalid quantity or price!" << endl;
        }
     }


    float getTotalPrice()
    {
        float effictivePrice =  pricePerItem;

        if (pricePerItem > 2000)
        {
            effictivePrice -= 500;
        }

        return quantity * effictivePrice;
    }

    int getQuantity()
    {
        return quantity;
    }

    float getUnitPrice()
    {
        return pricePerItem;
    }
};

int main()
{
    product item1;
    product item2;
    product item3;

    item1.setProduct(1, 2500);
    item2.setProduct(2, 2500);
    item3.setProduct(4, 250);

    cout << "Items Bought:" << item1.getQuantity() << endl;
    cout << " Price per Item(before discount): $" << item1.getUnitPrice() << endl;
    cout << "Total cost(after discount if any): $" << item1.getTotalPrice() << endl;
    cout << "Items Bought:" << item2.getQuantity() << endl;
    cout << " Price per Item(before discount): $" << item2.getUnitPrice() << endl;
    cout << "Total cost(after discount if any): $" << item2.getTotalPrice() << endl;
     cout << "Items Bought:" << item3.getQuantity() << endl;
    cout << " Price per Item(before discount): $" << item3.getUnitPrice() << endl;
    cout << "Total cost(after discount if any): $" << item3.getTotalPrice() << endl;
    
    return 0;
}
