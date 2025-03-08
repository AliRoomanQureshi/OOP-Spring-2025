#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    virtual void displayDetails() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a) {
        subject = sub;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout<<"Subject: "<<subject<<endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string area) : Person(n, a) {
        researchArea = area;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout<<"Research Area: "<<researchArea<<endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string sub, string area, int pubs) 
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, area) {
        publications = pubs;
    }

    void displayDetails() override {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Research Area: "<<researchArea<<endl;
        cout<<"Publications: "<<publications<<endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout<<"Enter name: ";
    getline(cin, name);
    cout<<"Enter age: ";
    cin>>age;
    cin.ignore();
    cout<<"Enter subject: ";
    getline(cin, subject);
    cout<<"Enter research area: ";
    getline(cin, researchArea);
    cout<<"Enter number of publications: ";
    cin>>publications;

    Professor prof(name, age, subject, researchArea, publications);

    cout<<"\nProfessor Details:\n";
    prof.displayDetails();

    return 0;
}
