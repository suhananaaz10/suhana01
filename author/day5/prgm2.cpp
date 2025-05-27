#include <iostream>
using namespace std;

class Invoice
{
public:
    void generateInvoice(int productId)
    {
        cout << "Generating invoice for product ID:" << productId << endl;
        cout << "Default quantity: 1| No discount applied." << endl;
    }

    void generateInvoice(int productId, int quantity)
    {
        cout << "Genarating invoice for produvt ID:" << productId << endl;
        cout << "Quantity:" << quantity << " | No discount applied." << endl;
    }

    void generateInvoice(int productId, int quantity, float discount)
    {
         cout << "Genarating invoice for produvt ID:" << productId << endl;
         cout << "Quantity:" << quantity << " | Discount:" << discount << "%" << endl;
    }
};

int main ()
{
    Invoice inv;

    inv.generateInvoice(101);
    inv.generateInvoice(102, 3);
    inv.generateInvoice(103, 5, 10.5);

    return 0;

}