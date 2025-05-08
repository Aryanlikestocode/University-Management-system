#include <iostream>
#include <vector>
#include <string>
#include "StudentManager.h"
using namespace std;

// Function declarations
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
            case 1:
                addStudent(studentManager);
                break;
            case 2:
                updateStudent(studentManager);
                break;
            case 3:
                deleteStudent(studentManager);
                break;
            case 4:
                searchStudents(studentManager);
                break;
            case 5:
                viewAllStudents(studentManager);
                break;
            case 0:
                running = false;
                cout << "Thank you for using the Student Management System!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        if (running) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}
// [Function implementations omitted for brevity]