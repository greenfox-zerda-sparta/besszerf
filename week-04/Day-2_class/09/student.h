#ifndef STUDENT_H_
#define STUDENT_H_
#include <vector>

using namespace std;

    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

class Student {
private:
  string name;
  vector<int> grades;

public:
  Student( string name);
  void add_grade(int grade);
  float get_average();
};

#endif /* STUDENT_H_ */
