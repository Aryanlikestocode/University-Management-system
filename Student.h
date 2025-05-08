#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string id;
    string name;
    string email;
    string phone;
    string address;
    string courseName;
    string grade;

public:
    Student() {}
    Student(string id, string name, string email, string phone, string address, string courseName, string grade) {
        this->id = id;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->address = address;
        this->courseName = courseName;
        this->grade = grade;
    }

    string getId() { return id; }
    string getName() { return name; }
    string getEmail() { return email; }
    string getPhone() { return phone; }
    string getAddress() { return address; }
    string getCourseName() { return courseName; }
    string getGrade() { return grade; }

    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }
    void setPhone(string phone) { this->phone = phone; }
    void setAddress(string address) { this->address = address; }
    void setCourseName(string courseName) { this->courseName = courseName; }
    void setGrade(string grade) { this->grade = grade; }
};

#endif
