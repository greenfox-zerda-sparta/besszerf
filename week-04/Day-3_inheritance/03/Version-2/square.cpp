#include "square.hpp"

#include <iostream>
#include <string>

using namespace std;

Square::Square(){
  Shape();
};

Square::Square(float height, float width) {
  Shape();
  set_height(height);
  set_width(width);
}

string* Square::getName() {
  return new string("Square");
}

float Square::calculate_area() {
  return get_width() * get_height();
}

float Square::get_area() {
  *mArea = calculate_area();
  return *mArea;
}
