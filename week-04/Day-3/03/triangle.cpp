#include "triangle.hpp"

#include <iostream>
#include <string>

using namespace std;


Triangle::Triangle(){
  height = 0;
  width = 0;
  mArea = 0;
};

Triangle::Triangle(float height, float width) {
  this->height = height;
  this->width = width;
  mArea = 0;
}

string* Triangle::getName() {
  return new string("Triangle");
}

float Triangle::calculate_area() {
  return width*height/2;
}

float Triangle::get_area() {
  mArea = calculate_area();
  return mArea;
}
