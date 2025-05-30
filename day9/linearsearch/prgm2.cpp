#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students:";
    cin >> n;

    int *rolls = new int[n];

    cout << "Enter student roll number:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ".";
        cin >> rolls[i];
    }

    int key;
    cout << "enter the roll number to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (rolls[i] == key)
        {
            cout << "Roll number " << key << "found at position" << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Roll number " << key << "not found." << endl;
    }

    delete[] rolls;
    return 0;

}