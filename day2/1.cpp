#include<iostream>
using namespace std;
int main()
{
    int i,n,j;
    cout<<"enter the n value:";
    cin>>n;
    for(i=0;i<=n;i++){
        for(j=0;j<i;j++)
            cout<<j<<endl;
    }
    return 0;
}