#include <iostream>
using  namespace std;
class ATM
{
private:
    int pin = 1234;
    double balance =5000;

    bool verifyPin(int enteredPin)
    {
        return enteredPin == pin;
    }

public:

    void withdrawCash(int enteredPin, double amount)
    {
        if (verifyPin(enteredPin))
        {
            if (amount <= balance)
            {
                balance -= amount;
                cout << "Withdrawal succesful. Remaining balance:" << balance << endl;
            }
            else
            {
                cout << "Insufficient balance." << endl;
            }
        }
        else
        {
            cout << "Invalid PIN!" << endl;
        }
     }

     void checkBalance(int enteredPin)
     {
        if (verifyPin(enteredPin))
        {
            cout << "Your balance is: " << balance << endl;
        }
        else
        {
            cout << "Invalid PIN!" << endl;
        }
        
     }
};

int main()
{
    ATM myATM;

    myATM.withdrawCash(1234,1000);
    myATM.checkBalance(1234);

    myATM.withdrawCash(1111,500);
    return 0;
}