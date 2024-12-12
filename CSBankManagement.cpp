#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 10;

class BankAccount {
public:
    int id;
    string owner;
    double balance;

    void display() {
        cout << "ID: " << id << ", Owner: " << owner << ", Balance: $" << fixed << setprecision(2) << balance << endl;
    }
}; 

BankAccount accounts[MAX_ACCOUNTS];
int currentSize = 0;
int nextId = 1;

void showBalance(int accountId);
void createAccount();
void deposit(int accountId);  
void withdraw(int accountId);
void deleteAccount();
void listAccounts();

int main() {
    int choice;
    int accountId;

    do {
        cout << "Welcome to CSBank!\n";
        cout << "What would you like to do today?\n\n";
        
        cout << "1. List Accounts\n";
        cout << "2. Create Account\n";
        cout << "3. Show Balance\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Delete Account\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();
        fflush(stdin);

        switch (choice) {
            case 1: listAccounts();
                    break;
            case 2: createAccount();
                    break;
            case 3: cout << "Enter Account ID: ";
                    cin >> accountId;
                    showBalance(accountId);
                    break;
            case 4: cout << "Enter Account ID: ";
                    cin >> accountId;
                    deposit(accountId);
                    break;
            case 5: cout << "Enter Account ID: ";
                    cin >> accountId;
                    withdraw(accountId);
                    break;
            case 6: deleteAccount();
                    break;
            case 7: cout << "Thanks for visiting!\n";
                    break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}

void showBalance(int accountId) {
    for (int i = 0; i < currentSize; ++i) {
        if (accounts[i].id == accountId) {
            cout << "Your balance is: $" << fixed << setprecision(2) << accounts[i].balance << '\n';
            return;
        }
    }
    cout << "Account not found.\n";
}

void createAccount() {
    if (currentSize >= MAX_ACCOUNTS) {
        cout << "Account list is full. Cannot create more accounts.\n";
        return;
    }
    BankAccount account;
    account.id = nextId++;
    cout << "Enter Account Owner: ";
    cin.ignore(); 
    getline(cin, account.owner);
    account.balance = 0;
    accounts[currentSize++] = account;
    cout << "Account created successfully.\n";
}



void deposit(int accountId) {
    double amount;
    for (int i = 0; i < currentSize; ++i) {
        if (accounts[i].id == accountId) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            if (amount > 0) {
                accounts[i].balance += amount;
                cout << "Deposited $" << fixed << setprecision(2) << amount << " to account ID " << accountId << '\n';
            } else {
                cout << "Invalid amount.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void withdraw(int accountId) {
    double amount;
    for (int i = 0; i < currentSize; ++i) {
        if (accounts[i].id == accountId) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                cout << "Withdrew $" << fixed << setprecision(2) << amount << " from account ID " << accountId << '\n';
            } else if (amount > accounts[i].balance) {
                cout << "Insufficient funds.\n";
            } else {
                cout << "Invalid amount.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void deleteAccount() {
    int accountId;
    cout << "Enter Account ID to delete: ";
    cin >> accountId;

    for (int i = 0; i < currentSize; ++i) {
        if (accounts[i].id == accountId) {
            for (int j = i; j < currentSize - 1; ++j) {
                accounts[j] = accounts[j + 1];
            }
            --currentSize;
            cout << "Account deleted successfully.\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void listAccounts() {
    if (currentSize == 0) {
        cout << "No accounts available.\n";
    } else {
        for (int i = 0; i < currentSize; ++i) {
            accounts[i].display();
        }
    }
}
