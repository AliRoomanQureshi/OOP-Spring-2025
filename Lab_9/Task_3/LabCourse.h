#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>

class LabCourse : public Course {
public:
    LabCourse(string code, int cr) : Course(code, cr) {}

    void displayInfo() const override {
        cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
    }

    double calculateGrade() const override {
        return 92.5;
    }
};

#endif
