#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "grades.h"

using namespace std;

int main() {
    GradeBook gradeBook;

    int numPrograms, numTests;
    double programWeight, testWeight, finalExamWeight;

    cout << "Enter the number of programs: ";
    cin >> numPrograms;
    cout << "Enter the number of tests: ";
    cin >> numTests;
    cout << "Enter the program weight (0-1): ";
    cin >> programWeight;
    cout << "Enter the test weight (0-1): ";
    cin >> testWeight;
    cout << "Enter the final exam weight (0-1): ";
    cin >> finalExamWeight;
    gradeBook.setup(numPrograms, numTests, 1, programWeight, testWeight, finalExamWeight);

    cin.ignore(); // Ignore newline character left in stream

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);
        int studentNumber;
        ss >> studentNumber;

        string name;
        getline(ss, name);

        char gradeType;
        double grade;
        while (ss >> gradeType >> grade) {
            switch (gradeType) {
                case 'P':
                    gradeBook.recordProgramGrade(grade);
                    break;
                case 'T':
                    gradeBook.recordTestGrade(grade);
                    break;
                case 'F':
                    gradeBook.changeGrade(studentNumber, gradeType, grade);
                    break;
            }
        }

        gradeBook.calculateFinalGrade();
        gradeBook.addStudent(name, "", studentNumber);
        auto it = gradeBook.findStudentByNumber(studentNumber);
        if (it == gradeBook.students_.end()) {
          throw std::invalid_argument("Student not found");
  }
        double semesterGrade = it->semesterGrade;


        cout << studentNumber << " " << name << " " << semesterGrade << endl;
    }

    return 0;
}
