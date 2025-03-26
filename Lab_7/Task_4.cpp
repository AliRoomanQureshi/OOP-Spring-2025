#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(const string& n, int a, const string& c, const string& addr = "")
        : name(n), age(a), contactNumber(c), address(addr) {}

    virtual void displayInfo() {
        cout<<"Name: "<<name<<", Age: "<<age<<", Contact: "<<contactNumber;
        if (!address.empty()) {
            cout<<", Address: "<<address;
        }
        cout<<endl;
    }

    virtual void updateInfo(const string& newContact, const string& newAddress = "") {
        contactNumber = newContact;
        if (!newAddress.empty()) {
            address = newAddress;
        }
        cout<<"Information updated for "<<name<<endl;
    }

    virtual ~Person() {}
};

class Patient : public Person {
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(const string& n, int a, const string& c, int pID, const string& medHist, const string& doc)
        : Person(n, a, c), patientID(pID), medicalHistory(medHist), doctorAssigned(doc) {}

    void displayInfo() override {
        Person::displayInfo();
        cout<<"Patient ID: "<<patientID<<", Medical History: "<<medicalHistory 
            <<", Doctor Assigned: "<<doctorAssigned<<endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(const string& n, int a, const string& c, const string& spec, double fee, const string& pList)
        : Person(n, a, c), specialization(spec), consultationFee(fee), patientsList(pList) {}

    void displayInfo() override {
        Person::displayInfo();
        cout<<"Specialization: "<<specialization<<", Consultation Fee: $"<<consultationFee
            <<", Patients List: "<<patientsList<<endl;
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;

public:
    Nurse(const string& n, int a, const string& c, const string& ward, const string& shift)
        : Person(n, a, c), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout<<"Assigned Ward: "<<assignedWard<<", Shift Timings: "<<shiftTimings<<endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;

public:
    Administrator(const string& n, int a, const string& c, const string& dept, double sal)
        : Person(n, a, c), department(dept), salary(sal) {}

    void updateInfo(const string& newContact, const string& newDept, double newSalary) {
        Person::updateInfo(newContact);
        department = newDept;
        salary = newSalary;
        cout << "Administrator data updated for " << name << endl;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout<<"Department: "<<department<<", Salary: $"<<salary<<endl;
    }
};

int main() {
    Patient patient1("xyz", 22, "0323-3032211", 101, "Cardio", "abc");
    Doctor doctor1("Dr. abc", 45, "0312-6789901", "Cardiology", 5000, "xyx, abc");
    Nurse nurse1("pqr", 30, "0300-1122334", "ICU", "Night");
    Administrator admin1("typ", 40, "0345-5566778", "HR", 120000);

    cout << "\n--- Hospital Staff Information ---\n";
    doctor1.displayInfo();
    nurse1.displayInfo();
    admin1.displayInfo();

    cout << "\n--- Patient Records ---\n";
    patient1.displayInfo();

    cout << "\n--- Updating Administrator Information ---\n";
    admin1.updateInfo("0345-9988776", "Finance", 150000);
    admin1.displayInfo();

    return 0;
}
