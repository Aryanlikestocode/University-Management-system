#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H

#include "Student.h"
#include <vector>

class StudentManagementSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& s);
    Student* searchStudent(int rollNumber);
    void displayAllStudents() const;
};

#endif