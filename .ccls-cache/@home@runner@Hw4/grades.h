#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <vector>

enum OutputOrder { NAME, STUDENT_NUMBER };

class GradeBook {
public:
    void setup(int numPrograms, int numTests, int numFinalExams, double programWeight, double testWeight, double finalExamWeight);

    void addStudent(const std::string& lastName, const std::string& firstName, int studentNumber) {
        students.push_back({ lastName, firstName, studentNumber, {}, {}, {}, 0, 0, 0, 0 });
    }

    void recordProgramGrade(int programNumber);
    void recordTestGrade(int testNumber);
    void recordFinalExamGrade();
    void changeGrade(int studentNumber, char gradeType, double newGrade);
    void calculateFinalGrade();
    void outputGradeData(OutputOrder order);
    void saveData(const std::string& filename);
    void loadData(const std::string& filename);
    auto GradeBook::findStudentByNumber(int studentNumber) -> decltype(students_.begin()) {
      auto it = std::find_if(students_.begin(), students_.end(),
                             [studentNumber](const Student &student) {
                               return student.studentNumber == studentNumber;
                             });
      return it;
}

        }
        return students.end();
    }

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
};

#endif
