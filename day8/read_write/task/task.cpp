#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    char grade;
};

// Function to add a student to the file
void addStudent() {
    Student s;
    cout << "Enter student name: ";
    cin >> s.name;
    cout << "Enter student age: ";
    cin >> s.age;
    cout << "Enter student grade (A/B/C/D/F): ";
    cin >> s.grade;

    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open()) {
        outFile << s.name << " " << s.age << " " << s.grade << endl;
        outFile.close();
        cout << "Student record added!\n";
    } else {
        cerr << "Error opening file for writing.\n";
    }
}

// Function to display all students
void displayStudents() {
    ifstream inFile("students.txt");
    string line;
    cout << "\n--- Student Records ---\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

// Function to search student by name
void searchStudentByName() {
    string name;
    cout << "Enter student name to search: ";
    cin >> name;

    ifstream inFile("students.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string n;
        int age;
        char grade;
        iss >> n >> age >> grade;
        if (n == name) {
            cout << "Student Found: " << line << endl;
            found = true;
            break;
        }
    }

    inFile.close();
    if (!found) {
        cout << "Student not found.\n";
    }
}

// Function to update student's grade
void updateStudentGrade() {
    string name;
    char newGrade;
    cout << "Enter student name to update grade: ";
    cin >> name;
    cout << "Enter new grade: ";
    cin >> newGrade;

    ifstream inFile("students.txt");
    vector<Student> students;
    string line;
    bool updated = false;

    // Read all students into memory
    while (getline(inFile, line)) {
        istringstream iss(line);
        Student s;
        iss >> s.name >> s.age >> s.grade;
        if (s.name == name) {
            s.grade = newGrade;
            updated = true;
        }
        students.push_back(s);
    }
    inFile.close();

    // Write all students back
    ofstream outFile("students.txt");
    for (const Student &s : students) {
        outFile << s.name << " " << s.age << " " << s.grade << endl;
    }
    outFile.close();

    if (updated)
        cout << "Grade updated successfully!\n";
    else
        cout << "Student not found.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n===== Student Management Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Name\n";
        cout << "4. Update Student Grade\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudentByName();
                break;
            case 4:
                updateStudentGrade();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
     