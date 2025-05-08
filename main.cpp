#include <iostream>
#include <vector>
#include <string>
#include "StudentManager.h"
using namespace std;

void displayMenu();
int getChoice();
void addStudent(StudentManager& manager);
void updateStudent(StudentManager& manager);
void deleteStudent(StudentManager& manager);
void searchStudents(StudentManager& manager);
void viewAllStudents(StudentManager& manager);
void displayStudent(Student student);

int main() {
    StudentManager studentManager;
    bool running = true;
    
    cout << "Welcome to the Student Management System" << endl;
    
    while (running) {
        displayMenu();
        int choice = getChoice();
        
        switch (choice) {
            case 1: addStudent(studentManager); break;
            case 2: updateStudent(studentManager); break;
            case 3: deleteStudent(studentManager); break;
            case 4: searchStudents(studentManager); break;
            case 5: viewAllStudents(studentManager); break;
            case 0: running = false; cout << "Thank you for using the Student Management System!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
        
        if (running) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}

void displayMenu() {
    cout << "\n========= STUDENT MANAGEMENT SYSTEM =========\n";
    cout << "1. Add Student\n2. Update Student\n3. Delete Student\n4. Search Students\n5. View All Students\n0. Exit\n";
    cout << "===========================================\nEnter your choice: ";
}

int getChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void addStudent(StudentManager& manager) {
    string id, name, email, phone, address, courseName, grade;
    cout << "\n--- Add Student ---\n";
    cout << "Enter Student ID: "; getline(cin, id);
    cout << "Enter Student Name: "; getline(cin, name);
    cout << "Enter Student Email: "; getline(cin, email);
    cout << "Enter Student Phone: "; getline(cin, phone);
    cout << "Enter Student Address: "; getline(cin, address);
    cout << "Enter Course Name: "; getline(cin, courseName);
    cout << "Enter Grade: "; getline(cin, grade);
    Student student(id, name, email, phone, address, courseName, grade);
    cout << manager.addStudent(student) << endl;
}

void updateStudent(StudentManager& manager) {
    string id, name, email, phone, address, courseName, grade;
    cout << "\n--- Update Student ---\nEnter Student ID to update: ";
    getline(cin, id);
    Student student = manager.findStudentById(id);
    if (student.getId().empty()) { cout << "Student not found!" << endl; return; }
    cout << "Current Student Details:" << endl; displayStudent(student);
    cout << "\nEnter new details (leave blank to keep current value):" << endl;
    cout << "Enter Student Name [" << student.getName() << "]: "; getline(cin, name);
    if (!name.empty()) student.setName(name);
    cout << "Enter Student Email [" << student.getEmail() << "]: "; getline(cin, email);
    if (!email.empty()) student.setEmail(email);
    cout << "Enter Student Phone [" << student.getPhone() << "]: "; getline(cin, phone);
    if (!phone.empty()) student.setPhone(phone);
    cout << "Enter Student Address [" << student.getAddress() << "]: "; getline(cin, address);
    if (!address.empty()) student.setAddress(address);
    cout << "Enter Course Name [" << student.getCourseName() << "]: "; getline(cin, courseName);
    if (!courseName.empty()) student.setCourseName(courseName);
    cout << "Enter Grade [" << student.getGrade() << "]: "; getline(cin, grade);
    if (!grade.empty()) student.setGrade(grade);
    cout << manager.updateStudent(student) << endl;
}

void deleteStudent(StudentManager& manager) {
    string id;
    cout << "\n--- Delete Student ---\nEnter Student ID to delete: ";
    getline(cin, id);
    cout << manager.deleteStudent(id) << endl;
}

void searchStudents(StudentManager& manager) {
    string name;
    cout << "\n--- Search Students ---\nEnter student name to search: ";
    getline(cin, name);
    vector<Student> results = manager.searchStudents(name);
    if (results.empty()) cout << "No matching students found." << endl;
    else {
        cout << "\nMatching Students:" << endl;
        for (auto s : results) { displayStudent(s); cout << endl; }
        cout << "Total found: " << results.size() << endl;
    }
}

void viewAllStudents(StudentManager& manager) {
    cout << "\n--- All Students ---\n";
    vector<Student> students = manager.getAllStudents();
    if (students.empty()) cout << "No students found in the system." << endl;
    else {
        for (auto s : students) { displayStudent(s); cout << endl; }
        cout << "Total students: " << students.size() << endl;
    }
}

void displayStudent(Student student) {
    cout << "ID: " << student.getId() << endl;
    cout << "Name: " << student.getName() << endl;
    cout << "Email: " << student.getEmail() << endl;
    cout << "Phone: " << student.getPhone() << endl;
    cout << "Address: " << student.getAddress() << endl;
    cout << "Course: " << student.getCourseName() << endl;
    cout << "Grade: " << student.getGrade() << endl;
}
