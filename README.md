# University Management System (C++)

A modular and extensible C++ project simulating a real-world University Management System using core Object-Oriented Programming (OOP) principles: Classes, Encapsulation, Inheritance, Polymorphism, and Exception Handling.

## Key Features

### Object-Oriented Design
- Core Classes: Person, Student, Professor, Course, Department
- Encapsulated Classes: GradeBook, EnrollmentManager
- Polymorphism: displayDetails(), calculatePayment() methods overridden in derived classes

### Inheritance Hierarchy
- Student → UndergraduateStudent, GraduateStudent
- Professor → AssistantProfessor, AssociateProfessor, FullProfessor

### Relationships
- Composition: Departments own Professors
- Aggregation: 
  - Courses have Professors and Students
  - Graduate Students have Professors as advisors

### Exception Handling
- Custom exceptions: UniversitySystemException, EnrollmentException, GradeException, PaymentException, etc.
- Validates inputs like age, GPA, course credits, etc.

### System Integration
- Unified UniversitySystem class manages: 
  - Departments, Courses, Students, Professors
  - Enrollments, Grades, Payments
  - Semester operations and reporting
