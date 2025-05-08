#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <vector>
#include "StudentDAO.h"
using namespace std;

class StudentManager {
private:
    StudentDAO studentDAO;

public:
    StudentManager() {
        studentDAO = StudentDAO();
    }

    string addStudent(Student student) {
        if (student.getId().empty()) return "Student ID cannot be empty";
        if (student.getName().empty()) return "Student name cannot be empty";
        if (student.getEmail().empty()) return "Student email cannot be empty";

        Student existingStudent = studentDAO.findStudentById(student.getId());
        if (!existingStudent.getId().empty()) {
            return "Student with this ID already exists";
        }

        if (studentDAO.addStudent(student)) return "Student added successfully";
        return "Failed to add student";
    }

    string updateStudent(Student student) {
        if (student.getId().empty()) return "Student ID cannot be empty";
        if (student.getName().empty()) return "Student name cannot be empty";
        if (student.getEmail().empty()) return "Student email cannot be empty";

        Student existingStudent = studentDAO.findStudentById(student.getId());
        if (existingStudent.getId().empty()) return "Student not found";

        if (studentDAO.updateStudent(student)) return "Student updated successfully";
        return "Failed to update student";
    }

    string deleteStudent(string id) {
        if (id.empty()) return "Invalid student ID";
        if (studentDAO.deleteStudent(id)) return "Student deleted successfully";
        return "Student not found";
    }

    Student findStudentById(string id) {
        if (id.empty()) return Student();
        return studentDAO.findStudentById(id);
    }

    vector<Student> getAllStudents() {
        return studentDAO.getAllStudents();
    }

    vector<Student> searchStudents(string name) {
        vector<Student> result;
        vector<Student> allStudents = getAllStudents();
        
        for (int i = 0; i < allStudents.size(); i++) {
            string studentName = allStudents[i].getName();
            string searchName = name;
            transform(studentName.begin(), studentName.end(), studentName.begin(), ::tolower);
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

            if (studentName.find(searchName) != string::npos) {
                result.push_back(allStudents[i]);
            }
        }
        
        return result;
    }
};

#endif
