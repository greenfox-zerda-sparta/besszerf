#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_
#include <string>
#include "shape.hpp"

using namespace std;

class Triangle : public Shape {

  public:
    string* getName();

};

#endif /* TRIANGLE_HPP_ */
