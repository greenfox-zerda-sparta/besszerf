/*
 * point2d.cpp
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */
#include "point2d.h"
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

bool Point2d::operator == (const Point2d& other_point) {
   if(x == other_point.x && y == other_point.y) {
      return true;
   }
   return false;
}

