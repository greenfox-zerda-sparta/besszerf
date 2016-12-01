#include "triangle.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a triangle class that takes a length parameter and prints a triangle like this:
    //   *
    //   **
    //   ***
    //   ****
    //   *****
    //   ******
    // It should take a number as parameter that describes how many lines the triangle has
  Triangle my_triangle(5);
  my_triangle.print_triangle();
  return 0;
}
