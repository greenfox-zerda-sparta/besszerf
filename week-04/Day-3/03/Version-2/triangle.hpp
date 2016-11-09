#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_
#include <string>
#include "shape.hpp"

using namespace std;

class Triangle : public Shape {

  public:
    Triangle();
    Triangle(float, float);
    string* getName();
    float get_area();

  private:
    float calculate_area();
    float* height;
    float* width;

};

#endif /* TRIANGLE_HPP_ */
