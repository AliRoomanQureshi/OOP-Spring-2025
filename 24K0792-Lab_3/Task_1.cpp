#include <iostream>
#include <string>

using namespace std;

class wallet {
    private:
        string OwnerName;
        float totalBalance;
        string TransactionHistory[100];
        int TransactionNum;

    public:
        wallet() {
            totalBalance = 0;
            TransactionNum = 0;
        }
        wallet(string Name) {
            OwnerName = Name;
            totalBalance = 0;
            TransactionNum = 0;
        }
        void addMoney(float amount){
            totalBalance += amount;
            if (TransactionNum < 100) {
                TransactionHistory[TransactionNum] = "Deposited amount of $" + to_string(amount) + " in your account.";
                TransactionNum++;
            }
        }
        void spendMoney(float amount){
            if (amount>0 && amount<=totalBalance) {
                totalBalance -= amount;
                if (TransactionNum<100) {
                    TransactionHistory[TransactionNum] = "Spent: $" + to_string(amount);
                    TransactionNum++;
                }
                cout<<"Transaction successful!\n";
            }
            else {
                cout<<"Insufficient balance or invalid amount!\n";
            }
        }
        void displayTransactionHistory(){
            for (int i=0;i<TransactionNum;i++) {
                cout<<TransactionHistory[i]<<"\n";
            }
        }   
};
int main() {
    string name;
    cout<<"Enter name for the account of the person: ";
    cout << "\n--- Transactions for "<<name<<" ---\n";
    wallet W(name);
    W.addMoney(500000);
    W.spendMoney(35000);
    W.displayTransactionHistory();
    W.addMoney(50000);
    W.spendMoney(10000);
    W.displayTransactionHistory();
    return 0;
}
