#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Employee {
    string name;
    string shift;
};

int main() {
    int numEmployees;

    cout << "Enter the number of employees checked in today: ";
    cin >> numEmployees;
    cin.ignore(); 

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter name of employee #" << (i + 1) << ": ";
        getline(cin, employees[i].name);

        cout << "Enter shift (Morning/Afternoon/Night) for " << employees[i].name << ": ";
        getline(cin, employees[i].shift);
    }

    cout << "\n--- Employee List ---\n";
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Name: " << employees[i].name << ", Shift: " << employees[i].shift << endl;
    }

    map<string, int> shiftCount;
    for (int i = 0; i < numEmployees; ++i) {
        shiftCount[employees[i].shift]++;
    }

    cout << "\n--- Shift Summary ---\n";
    for (const auto& pair : shiftCount) {
        cout << "Shift: " << pair.first << ", Employees: " << pair.second << endl;
    }

    delete[] employees;

    return 0;
}