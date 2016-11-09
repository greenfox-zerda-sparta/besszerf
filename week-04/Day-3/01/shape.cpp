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

Shape::~Shape() {}

string* Triangle::getName() {
  return new string("Triangle");
}

string* Square::getName() {
  return new string("Square");
}
