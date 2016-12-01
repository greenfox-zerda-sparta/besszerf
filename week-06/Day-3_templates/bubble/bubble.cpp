/*
 * bubble.cpp
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */
#include "bubble.h"

Bubble::Bubble() {
  position.set_x(rand() %10);
  position.set_y(rand() %10);
  std::cout << "Random Position of bubble (x, y) = ("<< position.get_x() << ", " << position.get_y() << ")"<< std::endl;
  speed_vector.set_x(rand() %10);
  speed_vector.set_y(rand() %10);
  std::cout << "   Speed vector (x, y) = ("<< speed_vector.get_x() << ", " << speed_vector.get_y() << ")"<< std::endl;
}

void Bubble::move() {
  position.set_x(position.get_x() + speed_vector.get_x());
  position.set_y(position.get_y() + speed_vector.get_y());
  std::cout << "Bubble moved. New position (x, y) = ("<< position.get_x() << ", " << position.get_y() << ")"<< std::endl;
}
