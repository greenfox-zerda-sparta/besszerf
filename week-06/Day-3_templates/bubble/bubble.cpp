/*
 * bubble.cpp
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */
#include "bubble.h"

void Point2d::set_x(int x) {
  this->x = x;
}

void Point2d::set_y(int y) {
  this->y = y;
}

int Point2d::get_x() {
  return x;
}

int Point2d::get_y() {
  return y;
}

Bubble::Bubble() {
  position.set_x(rand() %10);
  position.set_y(rand() %10);
  std::cout << "Random Position of bubble (x, y) = ("<< position.get_x() << ", " << position.get_y() << ")"<< std::endl;
}
