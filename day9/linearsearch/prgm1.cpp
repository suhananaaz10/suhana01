#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 2, 7, 1, 9, 8};
    int key = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (arr [i] == key)
        {
            cout << "Element " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Element " << key << "not found." << endl;
    }
    return 0;
}