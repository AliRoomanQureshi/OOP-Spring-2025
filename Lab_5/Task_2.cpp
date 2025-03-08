#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;
    int numScores;

public:
    Student(int id, string name, int scores[], int numScores) {
        this->id = id;
        this->name = name;
        this->numScores = numScores;
        this->scores = new int[numScores];
        for (int i=0;i<numScores;i++) {
            this->scores[i] = scores[i];
        }
    }

    Student(const Student& other) {
        id = other.id;
        name = other.name;
        numScores = other.numScores;
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
    }

    void display() const {
        cout<<"Student ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Exam Scores: ";
        for (int i=0;i<numScores;i++) {
            cout<<scores[i]<<" ";
        }
        cout<<endl;
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int scores1[] = {95, 90, 92};
    Student s1(101,"Ali",scores1,3);
    
    cout<<"Original Student Details:"<<endl;
    s1.display();
    Student s2 = s1;
    
    cout<<"\nCopied Student Details (For Verification):"<<endl;
    s2.display();
    return 0;
}
