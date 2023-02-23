#include "grades.h"

// Constructor
GradeBook::GradeBook() {
  numPrograms_ = 0;
  numTests_ = 0;
  numFinalExams_ = 0;
  programWeight_ = 0;
  testWeight_ = 0;
  finalExamWeight_ = 0;
}

// Setup function
void GradeBook::setup(int numPrograms, int numTests, int numFinalExams,
                      double programWeight, double testWeight,
                      double finalExamWeight) {
  numPrograms_ = numPrograms;
  numTests_ = numTests;
  numFinalExams_ = numFinalExams;
  programWeight_ = programWeight;
  testWeight_ = testWeight;
  finalExamWeight_ = finalExamWeight;
}

// Add a new student to the grade book
void GradeBook::add_student(const std::string &lastName,
                            const std::string &firstName, int studentNumber) {
  Student student(lastName, firstName, studentNumber, numPrograms_, numTests_,
                  numFinalExams_);
  students_.push_back(student);
}

// Record a program grade for all students
void GradeBook::record_program_grade(int programNumber) {
  if (programNumber < 1 || programNumber > numPrograms_) {
    throw std::invalid_argument("Invalid program number");
  }
  for (auto &student : students_) {
    double grade;
    std::cout << "Enter program grade for " << student.getFullName()
              << " (0-100): ";
    std::cin >> grade;
    student.recordProgramGrade(programNumber, grade);
  }
}

// Record a test grade for all students
void GradeBook::record_test_grade(int testNumber) {
  if (testNumber < 1 || testNumber > numTests_) {
    throw std::invalid_argument("Invalid test number");
  }
  for (auto &student : students_) {
    double grade;
    std::cout << "Enter test grade for " << student.getFullName()
              << " (0-100): ";
    std::cin >> grade;
    student.recordTestGrade(testNumber, grade);
  }
}

// Record the final exam grade for all students
void GradeBook::record_final_exam_grade() {
  for (auto &student : students_) {
    double grade;
    std::cout << "Enter final exam grade for " << student.getFullName()
              << " (0-100): ";
    std::cin >> grade;
    student.recordFinalExamGrade(grade);
  }
}

void GradeBook::change_grade(int studentNumber, char gradeType,
                             double newGrade) {
  auto it = findStudentByNumber(studentNumber);
  if (it == students.end()) {
    throw std::invalid_argument("Student not found");
  }
  if (gradeType == 'P') {
    if (newGrade < 0 || newGrade > 100) {
      throw std::invalid_argument("Invalid program grade");
    }
    it->programGrades.push_back(newGrade);
  } else if (gradeType == 'T') {
    if (newGrade < 0 || newGrade > 100) {
      throw std::invalid_argument("Invalid test grade");
    }
    it->testGrades.push_back(newGrade);
  } else if (gradeType == 'F') {
    if (newGrade < 0 || newGrade > 100) {
      throw std::invalid_argument("Invalid final exam grade");
    }
    it->finalExamGrade = newGrade;
  } else {
    throw std::invalid_argument("Invalid grade type");
  }
}

void GradeBook::calculate_final_grade() {
  for (auto &student : students) {
    double programTotal = 0.0;
    for (double grade : student.programGrades) {
      programTotal += grade;
    }
    double programAverage = programTotal / numPrograms;

    double testTotal = 0.0;
    for (double grade : student.testGrades) {
      testTotal += grade;
    }
    double testAverage = testTotal / numTests;

    double finalExamGrade = student.finalExamGrade;

    double finalGrade = programAverage * programWeight +
                        testAverage * testWeight +
                        finalExamGrade * finalExamWeight;
    student.finalGrade = finalGrade;
  }
}

void GradeBook::output_grade_data(OutputOrder order) {
  // Sort the students by name or number, depending on the order parameter
  if (order == OutputOrder::NAME) {
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) {
                return a.getFullName() < b.getFullName();
              });
  } else {
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) {
                return a.studentNumber < b.studentNumber;
              });
  }

  // Output the data for each student
  for (const auto &student : students) {
    std::cout << student.getFullName() << " (" << student.studentNumber
              << "):" << std::endl;
    std::cout << "Program grades: ";
    for (double grade : student.programGrades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;

    std::cout << "Test grades: ";
    for (double grade : student.testGrades) {
      std::cout << grade << " ";
    }
    std::cout << std::endl;

    std::cout << "Final exam grade: " << student.finalExamGrade << std::endl;
    std::cout << "Final grade: " << student.finalGrade << std::endl;
    std::cout << std::endl;
  }
}

void GradeBook::save_data(const std::string &filename) {
  std::ofstream outfile(filename, std::ios::out | std::ios::binary);
  if (!outfile) {
    throw std::runtime_error("Failed to open file for writing");
  }
  int numStudents = students.size();
  outfile.write(reinterpret_cast<char *>(&numStudents), sizeof(numStudents));
  for (auto &student : students) {
    outfile.write(reinterpret_cast<char *>(&student), sizeof(student));
  }
  outfile.close();
}

void GradeBook::load_data(const std::string &filename) {
  std::ifstream infile(filename, std::ios::in | std::ios::binary);
  if (!infile) {
    throw std::runtime_error("Failed to open file for reading");
  }
  int numStudents;
  infile.read(reinterpret_cast<char *>(&numStudents), sizeof(numStudents));
  students.clear();
  for (int i = 0; i < numStudents; i++) {
    Student student;
    infile.read(reinterpret_cast<char *>(&student), sizeof(student));
    students.push_back(student);
  }
  infile.close();
}

auto GradeBook::findStudentByNumber(int studentNumber) -> decltype(students_.begin()) {
  auto it = std::find_if(students_.begin(), students_.end(),
                         [studentNumber](const Student &student) {
                           return student.getNumber() == studentNumber;
                         });
  return it;
}

