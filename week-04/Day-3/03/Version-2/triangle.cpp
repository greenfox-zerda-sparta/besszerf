#include "triangle.hpp"

#include <iostream>
#include <string>

using namespace std;


Triangle::Triangle(){
  height = new float(0);
  width = new float(0);
  mArea = new float(0);
};

Triangle::Triangle(float height, float width) {
  this->height = new float(height);
  this->width = new float(width);
  mArea = new float(0);
}

string* Triangle::getName() {
  return new string("Triangle");
}

float Triangle::calculate_area() {
  return *width * *height/2;
}

float Triangle::get_area() {
  *mArea = calculate_area();
  return *mArea;
}
