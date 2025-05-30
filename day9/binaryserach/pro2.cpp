#include <iostream>
#include <string>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return - 1;
}
void displayBooks(int arr[], string titles[], int size)
{
    cout << "\nAvailable Books:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "ID:" << arr[i] << "-" << titles[i] << endl;
    }
}

int main()
{
    const int size = 7;
    int bookIDs[size] = {1001, 1005, 1020, 1030, 1050, 1100};
    string bookTitels[size] = {
        "C++ Basics", "Data structures", "alogorithms", "Database Systems",
        "Operating Systems", "Computer Networks", "AI Fundamentals"};

    displayBooks(bookIDs, bookTitels, size);

    int searchID;
    cout << "\nEnter the Book ID to search:";
    cin >> searchID;

    int index = binarySearch(bookIDs, size, searchID);

    if (index != -1)
    {
        cout << "Book Found:" << bookTitels[index]
            << "(ID:" << bookIDs[index] << ")" << endl;
    }
    else
    {
        cout << "Book with ID" << searchID << "not found." << endl;
    }

    return 0;   
}