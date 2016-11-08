#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

// Create a student Class
// that has a method `add_grade`, that takes a grade from 1 to 5
// an other method `get_average`, that returns the average of the
// grades

Student::Student(string name) {
  this->name = name;
}
void Student::add_grade(int grade) {
  grades.push_back(grade);
}
float Student::get_average() {
  float sum = 0;
  for(int i = 0; i < grades.size(); ++i) {
    sum += grades[i];
  }
  cout << endl;
  return sum/grades.size();
}
