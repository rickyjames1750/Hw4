#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <vector>

enum OutputOrder { NAME, STUDENT_NUMBER };

class GradeBook {
public:
    void setup(int numPrograms, int numTests, int numFinalExams, double programWeight, double testWeight, double finalExamWeight);
    void addStudent(const std::string& lastName, const std::string& firstName, int studentNumber);
    void recordProgramGrade(int programNumber);
    void recordTestGrade(int testNumber);
    void recordFinalExamGrade();
    void changeGrade(int studentNumber, char gradeType, double newGrade);
    void calculateFinalGrade();
    void outputGradeData(OutputOrder order);
    void saveData(const std::string& filename);
    void loadData(const std::string& filename);
private:
    struct Grade {
        double score;
        double weight;
    };

    struct Student {
        std::string lastName;
        std::string firstName;
        int studentNumber;
        std::vector<Grade> programGrades;
        std::vector<Grade> testGrades;
        Grade finalExamGrade;
        double programAverage;
        double testAverage;
        double finalExamScore;
        double semesterGrade;
    };

    std::vector<Student> students;

    std::vector<Student>::iterator findStudentByNumber(int studentNumber);
};

#endif
