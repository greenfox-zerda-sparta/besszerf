#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#include <string>

using namespace std;

class Shape {

  public:
    virtual string* getName();

    virtual ~Shape();

};

// Create 2 classes which inherit from the above defined class, Shape
// One should be Triangle, the other Square.
// Create their getName function based on the above example.
// Then watch what the code below does.
// If You find any typos, etc, correct them.

class Triangle : public Shape {

public:
  string* getName();

};

class Square : public Shape {

public:
  string* getName();

};

#endif /* SHAPE_HPP_ */
