/*
 * bubble.cpp
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */
#include "bubble.h"

Bubble::Bubble() {
  position.set_x(rand() %board_width);
  position.set_y(rand() %board_height);
  std::cout << "Random Position of bubble (x, y) = ("<< position.get_x() + 1 << ", " << position.get_y() + 1 << ")"<< std::endl;
  speed_vector.set_x(rand() %(move_units_max * 2 + 1) - move_units_max);
  speed_vector.set_y(rand() %(move_units_max * 2 + 1) - move_units_max);
  std::cout << "   Speed vector (x, y) = ("<< speed_vector.get_x() << ", " << speed_vector.get_y() << ")"<< std::endl;
}

void Bubble::move(Point2d new_position) {
  position = new_position;
  std::cout << "Bubble moved. New position (x, y) = ("<< position.get_x() + 1 << ", " << position.get_y() + 1 << ")"<< std::endl;
}

Point2d Bubble::get_next_position() {
  Point2d next_pos;
  next_pos.set_x(position.get_x() + speed_vector.get_x());
  next_pos.set_y(position.get_y() + speed_vector.get_y());
  return next_pos;
}

Point2d Bubble::get_position() {
  return position;
}

void Bubble::turn_horizontally() {
  position.set_x(position.get_x() * -1);
}

void Bubble::turn_vertically() {
  position.set_y(position.get_y() * -1);
}
