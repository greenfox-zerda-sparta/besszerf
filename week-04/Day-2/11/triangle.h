#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <vector>

using namespace std;

// Create a triangle class that takes a length parameter and prints a triangle like this:
//   *
//   **
//   ***
//   ****
//   *****
//   ******
// It should take a number as parameter that describes how many lines the triangle has

class Triangle{
  private:
     int size;

  public:
    Triangle(int size);
    const void print_triangle();
};

#endif /* TRIANGLE_H_ */
