# include <iostream>
using namespace std;

class User
{
public:
    string name, email;
    void login()
    {
        cout << name << "logged in with email" << email << endl;
    }
};


class Customer : public User
{
public:
    void browseProducts()
    {
        cout << name << "is browsing products." << endl;
    }
};

int main()
{
    Customer c;
    c.name = "Alice";
    c.email ="alice@example.com";
    c.login();
    c.browseProducts();
    return 0;
}