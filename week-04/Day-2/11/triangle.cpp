#include "triangle.h"

#include <iostream>
#include <string>

using namespace std;

// Create a triangle class that takes a length parameter and prints a triangle like this:
//   *
//   **
//   ***
//   ****
//   *****
//   ******
// It should take a number as parameter that describes how many lines the triangle has


Triangle::Triangle(int size) {
  this->size = size;
}

const void Triangle::print_triangle() {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i+1; j++) {
      cout << '*';
    }
    cout << endl;
  }
}
