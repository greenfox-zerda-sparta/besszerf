#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades
  Student jakab("Jakab Gipsz");
  jakab.add_grade(5);
  jakab.add_grade(3);
  cout << jakab.get_average() << endl;
  return 0;
}