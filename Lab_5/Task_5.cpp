#include <iostream>
#include <string>

using namespace std;

class Doctor {
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor(const string& name, const string& specialization, int experience)
        : name(name), specialization(specialization), experience(experience) {}

    void displayDoctorDetails() const {
        cout<<"Doctor Name: "<<name<<endl;
        cout<<"Specialization: "<<specialization<<endl;
        cout<<"Experience: "<<experience<<" years"<<endl;
        cout<<"----------------------"<<endl;
    }
};

class Hospital {
private:
    string hospitalName;
    Doctor* doctors[10];
    int doctorCount;

public:
    Hospital(const string& name) : hospitalName(name), doctorCount(0) {}

    void addDoctor(Doctor* doctor) {
        if (doctorCount < 10) {
            doctors[doctorCount] = doctor;
            doctorCount++;
        } else {
            cout<<"Cannot add more doctors, hospital is full!"<<endl;
        }
    }

    void displayDetails() const {
        cout<<"Hospital Name: "<<hospitalName<<endl;
        cout<<"Doctors currently working here:"<<endl;
        cout<<"----------------------"<<endl;
        if (doctorCount == 0) {
            cout<<"No doctors currently assigned."<<endl;
        } else {
            for (int i=0;i<doctorCount;i++) {
                doctors[i]->displayDoctorDetails();
            }
        }
    }
};

int main() {
    Doctor doc1("Dr. Ali", "Cardiologist", 15);
    Doctor doc2("Dr. Abrar", "Neurologist", 12);
    Doctor doc3("Dr. Rizwan", "Pediatrician", 8);

    Hospital hospital("City General Hospital");

    hospital.addDoctor(&doc1);
    hospital.addDoctor(&doc2);
    hospital.addDoctor(&doc3);

    hospital.displayDetails();

    return 0;
}
