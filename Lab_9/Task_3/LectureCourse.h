#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"
#include <iostream>

class LectureCourse : public Course {
public:
    LectureCourse(string code, int cr) : Course(code, cr) {}

    void displayInfo() const override {
        cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
    }

    double calculateGrade() const override {
        return 85.0;
    }
};

#endif
