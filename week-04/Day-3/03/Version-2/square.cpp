#include "square.hpp"

#include <iostream>
#include <string>

using namespace std;

Square::Square(){
  height = new float(0);
  width = new float(0);
  mArea = new float(0);
};

Square::Square(float height, float width) {
  this->height = new float(height);
  this->width = new float(width);
  mArea = new float(0);
}

string* Square::getName() {
  return new string("Square");
}

float Square::calculate_area() {
  return *width * *height;
}

float Square::get_area() {
  *mArea = calculate_area();
  return *mArea;
}
