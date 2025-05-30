#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students:";
    cin >> n;

    string *names = new string[n];

    cout << "Enter student names:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ".";
        cin >> names[i];
    }

    char choice;
    do
    {
        string key;
        cout << "enter the name to search: ";
        cin >> key;
        
        
        bool found = false;
        for (int i = 0; i < n; i++)
    {
            if (names[i] == key)
            {
                cout << "Students " << key << "found at position" << i + 1 << endl;
                found = true;
                break;
            }
    }
    if (!found)
    {
        cout << "Students " << key << "not found.\n";
    }

    cout << "Do you want to serach again? (y/n):";
    cin >> choice;
    }while (choice == 'y' || choice == 'y');
    

    delete[] names;
    return 0;
}
