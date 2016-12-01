/*
 * bubble.cpp
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */
#include "bubble.h"

int Bubble::max_x_position = board_width - 1;
int Bubble::min_x_position = 0;
int Bubble::max_y_position = board_height - 1;
int Bubble::min_y_position = 0;

Bubble::Bubble() {
  position.set_x(rand() %board_width);
  position.set_y(rand() %board_height);
  std::cout << "Random Position of bubble (x, y) = ("<< position.get_x() << ", " << position.get_y() << ")"<< std::endl;
  speed_vector.set_x(rand() %10);
  speed_vector.set_y(rand() %10);
  std::cout << "   Speed vector (x, y) = ("<< speed_vector.get_x() << ", " << speed_vector.get_y() << ")"<< std::endl;
}

int Bubble::move() {
  int wall_hits_count = 0;
  position.set_x(position.get_x() + speed_vector.get_x());
  position.set_y(position.get_y() + speed_vector.get_y());
  std::cout << "Bubble moved. New position (x, y) = ("<< position.get_x() << ", " << position.get_y() << ")"<< std::endl;
  return wall_hits_count;
}
