#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <vector>

using namespace std;

class Triangle{
  private:
     int size;

  public:
    Triangle(int size);
    const void print_triangle();
};

#endif /* TRIANGLE_H_ */
