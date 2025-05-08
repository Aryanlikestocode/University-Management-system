#include "Student.h"
#include <iostream>
#include <algorithm>

using namespace std;

Student::Student() : name("Unnamed"), rollNumber(0), cgpa(0.0f) {}

Student::Student(string n, int r, float c) {
    name = n;
    rollNumber = r;
    setCGPA(c);
}

Student::Student(const Student& other) {
    name = other.name;
    rollNumber = other.rollNumber;
    cgpa = other.cgpa;
    courses = other.courses;
}

Student::~Student() {}

void Student::addCourse(const string& course) {
    if (find(courses.begin(), courses.end(), course) == courses.end()) {
        courses.push_back(course);
    } else {
        cout << "Course already added.\n";
    }
}

void Student::setCGPA(float c) {
    if (c >= 0.0f && c <= 10.0f) {
        cgpa = c;
    } else {
        cout << "Invalid CGPA. Must be between 0 and 10.\n";
    }
}

void Student::displayInfo() const {
    cout << "Name: " << name << "\n";
    cout << "Roll Number: " << rollNumber << "\n";
    cout << "CGPA: " << cgpa << "\n";
    cout << "Courses Enrolled:\n";
    for (const string& course : courses) {
        cout << "  - " << course << "\n";
    }
}

int Student::getRollNumber() const {
    return rollNumber;
}