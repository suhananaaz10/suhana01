#include <iostream>
#include <vector>
using namespace std;

class User
{
private:
    int cardNumber;
    int pin;
    double balance;

public:
    User(int cardNum, int pinNum, double bal)
    {
        cardNumber = cardNum;
        pin = pinNum;
        balance = bal;
    }

    bool authenicate(int enteredCard, int enteredPin)
    {
        return (enteredCard == cardNumber && enteredPin == pin);
    }
    
    bool withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            return true;
        }
    }
}

