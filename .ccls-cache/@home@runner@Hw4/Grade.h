#ifndef GRADE_H
#define GRADE_H

class Grade {
public:
  Grade();
  Grade(double programGrade, double testGrade, double finalExamGrade);
  double programGrade;
  double testGrade;
  double finalExamGrade;
  double semesterGrade;
};

#endif // GRADE_H
