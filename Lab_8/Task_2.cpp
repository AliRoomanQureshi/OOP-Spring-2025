#include <iostream>
#include <string>
using namespace std;

class Manager;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }
    friend class Manager;
    friend void transferFunds(Account &from, Account &to, double amount);
};

void transferFunds(Account &from, Account &to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout<<"Transfer of Rs."<<amount<<" successful from Account "<<from.accountNumber<<" to Account "<<to.accountNumber<<"."<<endl;
    } else {
        cout<<"Transfer failed: Insufficient balance in Account "<<from.accountNumber<<"."<<endl;
    }
}

class Manager {
public:
    void displayAccount(const Account &acc) {
        cout<<"Account Number: "<<acc.accountNumber<<endl;
        cout<<"Balance: Rs."<<acc.balance<<endl;
    }

    void deposit(Account &acc, double amount) {
        acc.balance += amount;
        cout<<"Rs."<<amount<<" deposited into Account "<<acc.accountNumber<<"."<<endl;
    }

    void withdraw(Account &acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            cout<<"Rs."<<amount<<" withdrawn from Account "<<acc.accountNumber<<"."<<endl;
        } else {
            cout<<"Withdrawal failed: Insufficient balance in Account "<<acc.accountNumber<<"."<<endl;
        }
    }
};

int main() {
    Account acc1("ACC1001", 5000);
    Account acc2("ACC1002", 3000);

    Manager mgr;

    cout<<"Initial Account Details:"<<endl;
    cout<<"------------------------"<<endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    cout<<endl;

    mgr.deposit(acc1, 2000);
    mgr.withdraw(acc2, 1000);
    cout<<endl;

    cout<<"Account Details After Deposit and Withdrawal:"<<endl;
    cout<<"--------------------------------------------"<<endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    cout<<endl;

    transferFunds(acc1, acc2, 2500);
    cout<<endl;

    cout<<"Final Account Details:"<<endl;
    cout<<"----------------------"<<endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    return 0;
}