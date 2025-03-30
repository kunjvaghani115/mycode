#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Account
{
private:
    string name;
    int accNumber;
    double balance;

public:
    Account(string n, int accNum, double bal) : name(n), accNumber(accNum), balance(bal) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << " successfully! New Balance: " << balance << endl;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn " << amount << " successfully! New Balance: " << balance << endl;
        return true;
    }

    void display()
    {
        cout << "Account Holder: " << name << " | Account Number: " << accNumber << " | Balance: " << balance << endl;
    }

    void saveToFile()
    {
        ofstream file("account_data.txt", ios::app);
        file << name << " " << accNumber << " " << balance << endl;
        file.close();
    }
};

int main()
{
    vector<Account> accounts;
    accounts.push_back(Account("Kunj", 101, 5000));
    accounts.push_back(Account("Purv", 102, 7000));

    int choice, accNum;
    double amount;

    while (true)
    {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Accounts\n4. Save & Exit\nChoose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            for (auto &acc : accounts)
            {
                if (accNum == accNum)
                {
                    acc.deposit(amount);
                    break;
                }
            }
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            for (auto &acc : accounts)
            {
                if (accNum == accNum)
                {
                    acc.withdraw(amount);
                    break;
                }
            }
            break;

        case 3:
            for (auto &acc : accounts)
            {
                acc.display();
            }
            break;

        case 4:
            for (auto &acc : accounts)
            {
                acc.saveToFile();
            }
            cout << "Accounts saved successfully! Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}
