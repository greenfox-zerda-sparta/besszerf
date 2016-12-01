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
  fetch_next_position(temp_pos, wall_hits_count);
  position = *temp_pos;
  std::cout << "Bubble moved. New position (x, y) = ("<< position.get_x() + 1 << ", " << position.get_y() + 1 << ")"<< std::endl;
  return wall_hits_count;
}

void Bubble::fetch_next_position(Point2d* temp_pos, int &wall_hits_in_turn) {
  temp_pos->set_x(temp_pos->get_x() + speed_vector.get_x());
  temp_pos->set_y(temp_pos->get_y() + speed_vector.get_y());
  check_wall_hits(temp_pos, wall_hits_in_turn);
}

void Bubble::check_wall_hits(Point2d* temp_pos, int &wall_hits_in_turn) {
  int new_x_pos = temp_pos->get_x();
  int new_y_pos = temp_pos->get_y();
  check_right_wall(new_x_pos, wall_hits_in_turn);
  check_left_wall(new_x_pos, wall_hits_in_turn);
  check_top_wall(new_y_pos, wall_hits_in_turn);
  check_bottom_wall(new_y_pos, wall_hits_in_turn);
  if (wall_hits_in_turn > 0) {
    modify_position_after_wallhit(temp_pos, new_x_pos, new_y_pos);
  }
}

void Bubble::check_right_wall(int &x, int &wall_hits_in_turn) {
  if (x > max_x_position) {
    wall_hits_in_turn++;
    x = max_x_position + (max_x_position - x);
    change_speed_x_direction_after_wallhit();
  }
}

void Bubble::check_left_wall(int &x, int &wall_hits_in_turn) {
  if (x < min_x_position) {
    wall_hits_in_turn++;
    x = min_x_position + (min_x_position - x);
    change_speed_x_direction_after_wallhit();
  }
}

void Bubble::check_top_wall(int &y, int &wall_hits_in_turn) {
  if (y > max_y_position) {
    wall_hits_in_turn++;
    y = max_y_position + (max_y_position - y);
    change_speed_y_direction_after_wallhit();
  }
}

void Bubble::check_bottom_wall(int &y, int &wall_hits_in_turn) {
  if (y < min_y_position) {
    wall_hits_in_turn++;
    y = min_y_position + (min_y_position - y);
    change_speed_y_direction_after_wallhit();
  }
}

void Bubble::modify_position_after_wallhit(Point2d* temp_pos, int &new_x, int &new_y) {
  temp_pos->set_x(new_x);
  temp_pos->set_y(new_y);
  std::cout << "Bubble hits the wall!\n";
}

void Bubble::change_speed_x_direction_after_wallhit() {
  speed_vector.set_x(speed_vector.get_x() * -1);
}

void Bubble::change_speed_y_direction_after_wallhit() {
  speed_vector.set_y(speed_vector.get_y() * -1);
}

Point2d Bubble::get_position() {
  return position;
}
