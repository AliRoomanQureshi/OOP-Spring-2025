#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float bal) {
        accountNumber = accNum;
        balance = bal;
    }

    virtual void displayDetails() {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float bal, float rate) : Account(accNum, bal) {
        interestRate = rate;
    }

    void displayDetails() override {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum, float bal, float limit) : Account(accNum, bal) {
        overdraftLimit = limit;
    }

    void displayDetails() override {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
    }
};

int main() {
    int accNum;
    float balance, interestRate, overdraftLimit;

    cout<<"Enter savings account number: ";
    cin>>accNum;
    cout<<"Enter savings account balance: ";
    cin>>balance;
    cout<<"Enter savings account interest rate: ";
    cin>>interestRate;

    SavingsAccount savings(accNum, balance, interestRate);

    cout<<"\nSavings Account Details:\n";
    savings.displayDetails();

    cout<<"\nEnter checking account number: ";
    cin>>accNum;
    cout<<"Enter checking account balance: ";
    cin>>balance;
    cout<<"Enter checking account overdraft limit: ";
    cin>>overdraftLimit;

    CheckingAccount checking(accNum, balance, overdraftLimit);

    cout<<"\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}
