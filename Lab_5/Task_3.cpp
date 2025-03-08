#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 5;
const int MAX_PROJECTS = 5;

class Project;

class Employee {
private:
    string name;
    string designation;
    Project* projects[MAX_PROJECTS];
    int projectCount;

public:
    Employee(string name = "", string designation = "") {
        this->name = name;
        this->designation = designation;
        projectCount = 0;
        for (int i=0;i<MAX_PROJECTS;i++) {
            projects[i] = nullptr;
        }
    }

    string getName() const { 
        return name; 
    }
    string getDesignation() const { 
        return designation; 
    }

    bool addProject(Project* project) {
        if (projectCount < MAX_PROJECTS) {
            projects[projectCount++] = project;
            return true;
        } else {
            cout<<"Employee "<<name<<" is already in maximum projects."<<endl;
            return false;
        }
    }

    void displayProjects() const;
};

class Project {
private:
    string title;
    string deadline;
    Employee* employees[MAX_EMPLOYEES];
    int employeeCount;

public:
    Project(string title = "", string deadline = "") {
        this->title = title;
        this->deadline = deadline;
        employeeCount = 0;
        for (int i=0;i<MAX_EMPLOYEES;i++) {
            employees[i] = nullptr;
        }
    }

    string getTitle() const { 
        return title; 
    }

    bool addEmployee(Employee* emp) {
        if (employeeCount < MAX_EMPLOYEES) {
            employees[employeeCount++] = emp;
            emp->addProject(this);
            return true;
        } else {
            cout<<"Project "<<title<<" has maximum employees already."<<endl;
            return false;
        }
    }

    void displayDetails() const {
        cout<<"Project: "<<title<<" | Deadline: "<<deadline<<endl;
        cout<<"Assigned Employees:"<<endl;
        for (int i=0;i<employeeCount;i++) {
            cout<<" - " <<employees[i]->getName()<<" ("<<employees[i]->getDesignation()<<")"<<endl;
        }
    }
};


void Employee::displayProjects() const {
    cout<<"Employee: "<<name<<" ("<<designation<<") is working on:"<<endl;
    for (int i=0;i<projectCount;i++) {
        cout<<" - Project: "<<projects[i]->getTitle()<<endl;
    }
}

int main() {
    Employee emp1("Ali", "Developer");
    Employee emp2("Babar", "Designer");
    Employee emp3("Carry", "Tester");

    Project proj1("Project CT", "2025-04-01");
    Project proj2("Project CWC", "2025-05-15");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);

    proj2.addEmployee(&emp1);
    proj2.addEmployee(&emp3);

    cout << "\n--- Project Details ---\n";
    proj1.displayDetails();
    cout << endl;
    proj2.displayDetails();
    cout << endl;

    cout << "--- Employee Project Assignments ---\n";
    emp1.displayProjects();
    cout << endl;
    emp2.displayProjects();
    cout << endl;
    emp3.displayProjects();
    cout << endl;

    return 0;
}

