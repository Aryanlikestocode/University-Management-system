#include "StudentManagementSystem.h"
#include <iostream>

using namespace std;

void StudentManagementSystem::addStudent(const Student& s) {
    students.push_back(s);
}

Student* StudentManagementSystem::searchStudent(int rollNumber) {
    for (auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            return &student;
        }
    }
    return nullptr;
}

void StudentManagementSystem::displayAllStudents() const {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }
    for (const auto& student : students) {
        student.displayInfo();
        cout << "-------------------------\n";
    }
}