#ifndef SQUARE_HPP_
#define SQUARE_HPP_
#include "shape.hpp"
#include <string>

using namespace std;

class Square : public Shape {

public:
  Square();
  Square(float, float);
  string* getName();
  float get_area();

private:
  float calculate_area();
//  float* height;
//  float* width;

};

#endif /* SQUARE_HPP_ */
