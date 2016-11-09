#include "shape.hpp"

#include <iostream>
#include <string>

using namespace std;

// Create 2 classes which inherit from the above defined class, Shape
// One should be Triangle, the other Square.
// Create their getName function based on the above example.
// Then watch what the code below does.
// If You find any typos, etc, correct them.

string* Shape::getName() {
  return new string("Generic Shape");
}

Shape::Shape(){
  height = 0;
  width = 0;
  mArea = 0;
};

Shape::Shape(float height, float width) {
  this->height = height;
  this->width = width;
  mArea = 0;
}

Shape::~Shape(){};

const float Shape::get_height() {
  return height;
}

const float Shape::get_width() {
  return width;
}

void Shape::set_height(float height) {
  this->height = height;
}
void Shape::set_width(float width) {
  this->width = width;
}

float Shape::calculate_area() {
  return 0;
}

float Shape::get_area() { // virtual
  mArea = calculate_area();
  return mArea;
}
