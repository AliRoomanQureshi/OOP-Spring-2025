#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "InPatient [" << name << ", ID: " << id << "] receives:\n";
        cout << " - Hospital Room\n - IV Drips\n - 24/7 Monitoring\n";
    }

    double calculateCost() const override {
        return 1700.0;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "OutPatient [" << name << ", ID: " << id << "] receives:\n";
        cout << " - Doctor Consultation\n - Medicines\n - Tests if needed\n";
    }

    double calculateCost() const override {
        return 350.0;
    }
};

int main() {
    Patient* patients[2];

    patients[0] = new InPatient("Sara", "IP102");
    patients[1] = new OutPatient("Ahmed", "OP204");

    for (int i = 0; i < 2; i++) {
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << "\n\n";
        delete patients[i]; 
    }

    return 0;
}
