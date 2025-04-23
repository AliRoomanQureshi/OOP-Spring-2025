#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    Course* courses[2];
    courses[0] = new LectureCourse("CS101", 3);
    courses[1] = new LabCourse("CS101L", 1);

    for (int i = 0; i < 2; i++) {
        courses[i]->displayInfo();
        cout << "Grade: " << courses[i]->calculateGrade() << endl << endl;
        delete courses[i];
    }

    return 0;
}
