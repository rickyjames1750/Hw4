#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student();
    Student(const std::string& lastName, const std::string& firstName, int studentNumber);
    std::string getFullName() const;
    std::string lastName;
    std::string firstName;
    int studentNumber;
};

#endif  // STUDENT_H
