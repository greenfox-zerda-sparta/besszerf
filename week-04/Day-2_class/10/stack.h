#ifndef STACK_H_
#define STACK_H_
#include <vector>

using namespace std;

    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

class Stack{
  private:
    double* storage;
    int size;

  public:
    Stack(double input[], int size = 0);
    void push(double value);
    double pop();
    const int get_size();
};

#endif /* STACK_H_ */
