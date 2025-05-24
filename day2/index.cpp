#include<iostream>
using namespace std;
int main(){
    string name;
    int age;
    cout<<"enter your first name:";
    cin>>name;
    cout<<"enter your age:";
    cin>>age;
    cout<<"hello"<<name<<"!you are"<<age<<"yrs old"<<endl;;
    return 0;
}
#include<loststream>
using namespace std;

class book
{
public;
    string auther;
    string title;

    void display()
    (
        cout <<"-"<< title << endl;
    )
};

int main{}
{
    book b1;
    b1.author="alice";
    b1.title="c++";
    b1.display();//output:alice-20
    return 0;
}


#include<iostream>
using namespace std;

class Account{
    private:
     int balance;
    public:
     void setBalance(int b){
        balance=b;
     }
     int getBalance(){
        return balance;
     }
}

int main(){
    Account acc;
    acc.setBalance(1000);
    count <<"Balance:" << acc.getBalance()<<endl;//output:balance:1000
    return 0;
}
