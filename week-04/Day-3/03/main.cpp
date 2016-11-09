#include "shape.hpp"
#include "triangle.hpp"
#include "square.hpp"

#include <iostream>
#include <string>

using namespace std;

// Create 2 classes which inherit from the above defined class, Shape
// One should be Triangle, the other Square.
// Create their getName function based on the above example.
// Then watch what the code below does.
// If You find any typos, etc, correct them.

int main() {
  Shape* shape = new Shape(2, 3);
  Triangle* triangle = new Triangle(2, 3);
  Square* square = new Square(2, 3);
  Shape* a;
  cout << "I am a...  " << *shape->getName() << " ... my area is: " << shape->get_area() << endl;
  cout << "I am a...  " << *triangle->getName() << " ... my area is: " << triangle->get_area() << endl;
  cout << "I am a...  " << *square->getName() << " ... my area is: " << square->get_area()<< endl;

  a = square;
  cout << "I am a...  " << *a->getName() << " ... my area is: " << a->get_area() << endl;

  a = triangle;
  cout << "I am a...  " << *a->getName()<< " ... my area is: " << a->get_area() << endl;
  delete shape;
  delete triangle;
  delete square;
  delete a;
  return 0;
}
