#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Student.h"
using namespace std;

class StudentDAO {
private:
    string filename;

public:
    StudentDAO() {
        filename = "students.txt";
    }

    bool saveStudents(vector<Student> students) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Could not open file for writing!" << endl;
            return false;
        }

        for (int i = 0; i < students.size(); i++) {
            file << students[i].getId() << ","
                 << students[i].getName() << ","
                 << students[i].getEmail() << ","
                 << students[i].getPhone() << ","
                 << students[i].getAddress() << ","
                 << students[i].getCourseName() << ","
                 << students[i].getGrade() << endl;
        }

        file.close();
        return true;
    }

    vector<Student> loadStudents() {
        vector<Student> students;
        ifstream file(filename);
        
        if (!file.is_open()) {
            return students;
        }

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            
            Student student;
            size_t pos = 0;
            string token;
            int fieldIndex = 0;
            
            while ((pos = line.find(",")) != string::npos) {
                token = line.substr(0, pos);
                line.erase(0, pos + 1);
                
                switch (fieldIndex) {
                    case 0: student.setId(token); break;
                    case 1: student.setName(token); break;
                    case 2: student.setEmail(token); break;
                    case 3: student.setPhone(token); break;
                    case 4: student.setAddress(token); break;
                    case 5: student.setCourseName(token); break;
                }
                
                fieldIndex++;
            }
            
            student.setGrade(line);
            students.push_back(student);
        }
        
        file.close();
        return students;
    }

    bool addStudent(Student student) {
        vector<Student> students = loadStudents();
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == student.getId()) {
                return false;
            }
        }
        
        students.push_back(student);
        return saveStudents(students);
    }

    bool updateStudent(Student student) {
        vector<Student> students = loadStudents();
        bool found = false;
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == student.getId()) {
                students[i] = student;
                found = true;
                break;
            }
        }
        
        if (!found) {
            return false;
        }
        
        return saveStudents(students);
    }

    bool deleteStudent(string id) {
        vector<Student> students = loadStudents();
        bool found = false;
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                found = true;
                break;
            }
        }
        
        if (!found) {
            return false;
        }
        
        return saveStudents(students);
    }

    Student findStudentById(string id) {
        vector<Student> students = loadStudents();
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                return students[i];
            }
        }
        
        return Student();
    }

    vector<Student> getAllStudents() {
        return loadStudents();
    }
};

#endif
