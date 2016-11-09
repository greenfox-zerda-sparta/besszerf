#include "triangle.hpp"

#include <iostream>
#include <string>

using namespace std;


Triangle::Triangle(){
  Shape();
};

Triangle::Triangle(float height, float width) {
  Shape();
  set_height(height);
  set_width(width);
}

string* Triangle::getName() {
  return new string("Triangle");
}

float Triangle::calculate_area() {
  return get_width() * get_height()/2;
}

float Triangle::get_area() {
  *mArea = calculate_area();
  return *mArea;
}
