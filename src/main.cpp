#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
using namespace std;

// Base Exception
class UniversitySystemException : public exception {
protected:
    string message;
public:
    UniversitySystemException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(const string& msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(const string& msg) : UniversitySystemException("Grade Error: " + msg) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(const string& msg) : UniversitySystemException("Payment Error: " + msg) {}
};

// Base class
class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person(const string& name, int age, const string& ID, const string& contact)
        : name(name), age(age), ID(ID), contact(contact) {
        if (age <= 0 || age > 120) throw UniversitySystemException("Invalid age.");
        if (name.empty()) throw UniversitySystemException("Name cannot be empty.");
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact << endl;
    }

    virtual double calculatePayment() const {
        return 0.0;
    }

    virtual ~Person() {}
};

// Student class
class Student : public Person {
protected:
    string enrollmentDate;
    string program;
    double GPA;

public:
    Student(const string& name, int age, const string& ID, const string& contact,
            const string& enrollmentDate, const string& program, double GPA)
        : Person(name, age, ID, contact), enrollmentDate(enrollmentDate), program(program), GPA(GPA) {
        if (GPA < 0.0 || GPA > 4.0) throw UniversitySystemException("Invalid GPA.");
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA << endl;
    }

    double calculatePayment() const override {
        return 1000.0;
    }
};

// Undergraduate Student
class UndergraduateStudent : public Student {
    string major, minor, gradDate;
public:
    UndergraduateStudent(string name, int age, string ID, string contact,
                         string enrollmentDate, string program, double GPA,
                         string major, string minor, string gradDate)
        : Student(name, age, ID, contact, enrollmentDate, program, GPA),
          major(major), minor(minor), gradDate(gradDate) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor << ", Graduation: " << gradDate << endl;
    }
};

// Graduate Student
class GraduateStudent : public Student {
    string researchTopic, advisor, thesis;
public:
    GraduateStudent(string name, int age, string ID, string contact,
                    string enrollmentDate, string program, double GPA,
                    string researchTopic, string advisor, string thesis)
        : Student(name, age, ID, contact, enrollmentDate, program, GPA),
          researchTopic(researchTopic), advisor(advisor), thesis(thesis) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Research: " << researchTopic << ", Advisor: " << advisor << ", Thesis: " << thesis << endl;
    }
};

// Professor class
class Professor : public Person {
protected:
    string department, specialization, hireDate;
public:
    Professor(string name, int age, string ID, string contact,
              string department, string specialization, string hireDate)
        : Person(name, age, ID, contact),
          department(department), specialization(specialization), hireDate(hireDate) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Dept: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }
};

// Assistant Professor
class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string name, int age, string ID, string contact,
                       string department, string specialization, string hireDate)
        : Professor(name, age, ID, contact, department, specialization, hireDate) {}

    double calculatePayment() const override {
        return 5000.0;
    }
};

// Department class
class Department {
    string name, location;
    double budget;
    vector<Professor*> professors;

public:
    Department(string name, string location, double budget)
        : name(name), location(location), budget(budget) {}

    void addProfessor(Professor* prof) {
        professors.push_back(prof);
    }
};

// Main function to test polymorphism
int main() {
    try {
        UndergraduateStudent u("Alice", 20, "S101", "alice@example.com", "2023-08", "B.Tech", 3.8, "CSE", "Math", "2027-05");
        GraduateStudent g("Bob", 24, "S102", "bob@example.com", "2022-08", "M.Tech", 3.5, "AI", "Dr. X", "AI and Society");
        AssistantProfessor p("Dr. Smith", 45, "P101", "smith@example.com", "CSE", "ML", "2015-06");

        Person* people[] = { &u, &g, &p };
        for (Person* person : people) {
            person->displayDetails();
            cout << "Payment: $" << person->calculatePayment() << endl;
            cout << "--------" << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
