#include "grades.h"

void GradeBook::setup(int numPrograms, int numTests, int numFinalExams, double programWeight, double testWeight, double finalExamWeight) {
    // TODO: Implement the setup function
}

void GradeBook::addStudent(const std::string& lastName, const std::string& firstName, int studentNumber) {
    // TODO: Implement the addStudent function
}

void GradeBook::recordProgramGrade(int programNumber) {
    // TODO: Implement the recordProgramGrade function
}

void GradeBook::recordTestGrade(int testNumber) {
    // TODO: Implement the recordTestGrade function
}

void GradeBook::recordFinalExamGrade() {
    // TODO: Implement the recordFinalExamGrade function
}

void GradeBook::changeGrade(int studentNumber, char gradeType, double newGrade) {
    // TODO: Implement the changeGrade function
}

void GradeBook::calculateFinalGrade() {
    // TODO: Implement the calculateFinalGrade function
}

void GradeBook::outputGradeData(OutputOrder order) {
    // TODO: Implement the outputGradeData function
}

void GradeBook::saveData(const std::string& filename) {
    // TODO: Implement the saveData function
}

void GradeBook::loadData(const std::string& filename) {
    // TODO: Implement the loadData function
}

std::vector<Student>::iterator GradeBook::findStudentByNumber(int studentNumber) {
    // TODO: Implement the findStudentByNumber function
    return students.end();
}
