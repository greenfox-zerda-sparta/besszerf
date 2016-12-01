/*
 * bubble.h
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */

#ifndef BUBBLE_H_
#define BUBBLE_H_
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include "point2d.h"
#include "util.h"

class Bubble {
  public:
    Bubble();
    int move();
    Point2d get_position();
  private:
    Point2d position;
    Point2d speed_vector;
    static int max_x_position;
    static int min_x_position;
    static int max_y_position;
    static int min_y_position;
    void fetch_next_position(Point2d* temp_pos, int &wall_hits_in_turn);
    void check_wall_hits(Point2d* temp_pos, int &wall_hits_in_turn);
    void check_right_wall(int &x, int &wall_hits_in_turn);
    void check_left_wall(int &x, int &wall_hits_in_turn);
    void check_top_wall(int &y, int &wall_hits_in_turn);
    void check_bottom_wall(int &y, int &wall_hits_in_turn);
    void modify_position_after_wallhit(Point2d* temp_pos, int &new_x, int &new_y);
    void change_speed_x_direction_after_wallhit();
    void change_speed_y_direction_after_wallhit();
    int get_wall_hits(Point2d* temp_pos);
};

#endif /* BUBBLE_H_ */
