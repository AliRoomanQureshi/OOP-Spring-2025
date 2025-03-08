#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string n, float s) {
        name = n;
        salary = s;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string n, float s, float b) : Employee(n, s) {
        bonus = b;
    }


    void displayDetails() override {
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: $"<<salary<<endl;
        cout<<"Bonus: $"<<bonus<<endl;
    }
};

int main() {
    string name;
    float salary, bonus;

    cout<<"Enter manager's name: ";
    getline(cin, name);

    cout<<"Enter manager's salary: ";
    cin>>salary;

    cout<<"Enter manager's bonus: ";
    cin>>bonus;

    Manager manager(name, salary, bonus);

    cout<<"\nManager Details:\n";
    manager.displayDetails();

    return 0;
}
