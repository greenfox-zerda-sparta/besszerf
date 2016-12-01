#ifndef SQUARE_HPP_
#define SQUARE_HPP_
#include "shape.hpp"
#include <string>

using namespace std;

class Square : public Shape {

  public:
    string* getName();

};

#endif /* SQUARE_HPP_ */
