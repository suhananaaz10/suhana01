#include <iostream>

#include <fstream>

#include <string>

#include <ctime>

#include <exception>

using namespace std;


class InsufficientFundsException : public exception {

public:

    const char *what() const noexcept override {

        return "Withdrawal failed: Insufficient funds.";

    }

};

class AccountLockedException : public exception {

public:

    const char *what() const noexcept override {

        return "Account is locked due to 3 failed withdrawal attempts.";

    }

};


string getCurrentTime() {

    time_t now = time(0);

    char *dt = ctime(&now);

    string timeStr(dt);

    timeStr.pop_back(); 

    return timeStr;

}



void logAction(const string &message) {

    ofstream logFile("log.txt", ios::app);

    if (logFile) {

        logFile << "[" << getCurrentTime() << "] " << message << endl;

        logFile.close();

    }

}


void saveBalances(double balances[], int size) {

    ofstream outFile("balances.txt");

    for (int i = 0; i < size; ++i) {

        outFile << balances[i] << endl;

    }

    outFile.close();

}

// Load balances from file

void loadBalances(double balances[], int size) {

    ifstream inFile("balances.txt");

    for (int i = 0; i < size && inFile; ++i) {

        inFile >> balances[i];

    }

    inFile.close();

}

int main() {

    const int USER_COUNT = 3;

    double balances[USER_COUNT] = {1000.0, 800.0, 1200.0}; 

    int failedAttempts[USER_COUNT] = {0};

    loadBalances(balances, USER_COUNT); 

    int userID;

    cout << "Enter user ID (0-2): ";

    cin >> userID;

    if (userID < 0 || userID >= USER_COUNT) {

        cout << "Invalid user ID." << endl;

        return 1;

    }

    char choice;

    do {

        cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter option: ";

        int option;

        cin >> option;

        try {

            switch (option) {

                case 1:

                    cout << "Balance: $" << balances[userID] << endl;

                    logAction("User " + to_string(userID) + " checked balance.");

                    break;

                case 2: {

                    double depositAmount;

                    cout << "Enter deposit amount: ";

                    cin >> depositAmount;

                    if (depositAmount <= 0)

                        throw invalid_argument("Invalid deposit amount.");

                    balances[userID] += depositAmount;

                    cout << "Deposited $" << depositAmount << endl;

                    logAction("User " + to_string(userID) + " deposited $" + to_string(depositAmount));

                    break;

                }

                case 3: {

                    if (failedAttempts[userID] >= 3)

                        throw AccountLockedException();

                    double withdrawAmount;

                    cout << "Enter withdraw amount: ";

                    cin >> withdrawAmount;

                    if (withdrawAmount < 0)

                        throw invalid_argument("Invalid withdrawal amount.");

                    if (withdrawAmount > balances[userID]) {

                        failedAttempts[userID]++;

                        logAction("User " + to_string(userID) + " failed withdrawal attempt.");

                        if (failedAttempts[userID] >= 3)

                            throw AccountLockedException();

                        throw InsufficientFundsException();

                    }

                    balances[userID] -= withdrawAmount;

                    cout << "Withdrawn $" << withdrawAmount << endl;

                    logAction("User " + to_string(userID) + " withdrew $" + to_string(withdrawAmount));

                    failedAttempts[userID] = 0; // reset on success

                    break;

                }

                case 4:

                    cout << "Exiting...\n";

                    break;

                default:

                    cout << "Invalid choice.\n";

            }

        }

        catch (const AccountLockedException &ex) {

            cout << "Error: " << ex.what() << endl;

            logAction("User " + to_string(userID) + " locked out.");

        }

        catch (const exception &ex) {

            cout << "Exception: " << ex.what() << endl;

            logAction("Exception for user " + to_string(userID) + ": " + ex.what());

        }

        saveBalances(balances, USER_COUNT); 

        cout << "Do you want to continue (y/n)? ";

        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;

}