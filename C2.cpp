#include <iostream>
#include <string>
using namespace std;

class ServiceCentre {
    string shopName;
    string openingDate;
    string ownerName;

public:
    void inputShopDetails() {
        cout << "Enter the name of Service Centre: ";
        getline(cin, shopName);

        cout << "Enter the date when the shop was opened (dd-mm-yyyy): ";
        getline(cin, openingDate);

        cout << "Enter the name of owner:";
        getline(cin, ownerName);
    }

    void displayShopDetails() {
        cout << "\n--- Welcome to " << shopName << " ---\n";
        cout << "Opened on: " << openingDate << "\n";
        cout << "Owner is" << ownerName << "\n";

    }

    void showServices() {
        cout << "\nAvailable Services:\n";
        cout << "1. IRCTC(Train Ticket Booking)\n";
        cout << "2. Bus Ticket Booking\n";
        cout << "3. Flight Ticket Booking\n";
        cout << "4. Hotel Booking\n";
        cout << "Enter your choice (1-4): ";
    }

    void processService(int choice) {
        switch (choice) {
            case 1:
                cout << "Processing IRCTC(Train Ticket Booking).\n";
                break;
            case 2:
                cout << "Processing Bus Ticket Booking .\n";
                break;
            case 3:
                cout << "Processing Flight Ticket Booking.\n";
                break;
            case 4:
                cout << "Processing Hotel Booking.\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid service.\n";
        }
    }
};

int main() {
    ServiceCentre csc;
    int choice;

    csc.inputShopDetails();
    csc.displayShopDetails();
    csc.showServices();
    cin >> choice;

    csc.processService(choice);

    return 0;
}


