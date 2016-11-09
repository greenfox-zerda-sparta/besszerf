#include "square.hpp"

#include <iostream>
#include <string>

using namespace std;

Square::Square(){
  height = 0;
  width = 0;
  mArea = 0;
};

Square::Square(float height, float width) {
  this->height = height;
  this->width = width;
  mArea = 0;
}

string* Square::getName() {
  return new string("Square");
}

float Square::calculate_area() {
  return width*height;
}

float Square::get_area() {
  mArea = calculate_area();
  return mArea;
}
