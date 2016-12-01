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
  std::cout << "Random Position of bubble (x, y) = ("<< position.get_x() + 1 << ", " << position.get_y() + 1 << ")"<< std::endl;
  speed_vector.set_x(rand() %(move_units_max * 2 + 1) - move_units_max);
  speed_vector.set_y(rand() %(move_units_max * 2 + 1) - move_units_max);
  std::cout << "   Speed vector (x, y) = ("<< speed_vector.get_x() << ", " << speed_vector.get_y() << ")"<< std::endl;
}

int Bubble::move() {
  Point2d* temp_pos;
  temp_pos = &position;
  int wall_hits_count = 0;
  calculate_position(temp_pos, wall_hits_count);
  position = *temp_pos;
  std::cout << "Bubble moved. New position (x, y) = ("<< position.get_x() + 1 << ", " << position.get_y() + 1 << ")"<< std::endl;
  return wall_hits_count;
}

void Bubble::change_speed_x_direction() {
  speed_vector.set_x(speed_vector.get_x() * -1);
}

void Bubble::change_speed_y_direction() {
  speed_vector.set_y(speed_vector.get_y() * -1);
}

int Bubble::get_wall_hits(Point2d* temp_pos) {
  int hits_the_wall = 0;
  int new_x_pos = temp_pos->get_x();
  int new_y_pos = temp_pos->get_y();
  if (new_x_pos > max_x_position) {
    hits_the_wall++;
    new_x_pos = max_x_position + (max_x_position - new_x_pos);
    change_speed_x_direction();
  } else if (temp_pos->get_x() < min_x_position) {
    hits_the_wall++;
    new_x_pos = min_x_position + (min_x_position - new_x_pos);
    change_speed_x_direction();
  }
  if (new_y_pos > max_y_position) {
    hits_the_wall++;
    new_y_pos = max_y_position + (max_y_position - new_y_pos);
    change_speed_y_direction();
  } else if (temp_pos->get_y() < min_y_position) {
    hits_the_wall++;
    new_y_pos = min_y_position + (min_y_position - new_y_pos);
    change_speed_y_direction();
  }
  if (hits_the_wall > 0) {
    temp_pos->set_x(new_x_pos);
    temp_pos->set_y(new_y_pos);
    std::cout << "Bubble hits the wall!\n";
  }
  return hits_the_wall;
}

void Bubble::calculate_position(Point2d* temp_pos, int &wall_hits_in_turn) {
  temp_pos->set_x(temp_pos->get_x() + speed_vector.get_x());
  temp_pos->set_y(temp_pos->get_y() + speed_vector.get_y());
  wall_hits_in_turn += get_wall_hits(temp_pos);
}

Point2d Bubble::get_position() {
  return position;
}
