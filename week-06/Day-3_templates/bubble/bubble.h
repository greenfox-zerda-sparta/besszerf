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
  private:
    Point2d position;
    Point2d speed_vector;
    static int max_x_position;
    static int min_x_position;
    static int max_y_position;
    static int min_y_position;
  public:
    Bubble();
    int move();
    Point2d get_position();
    Point2d get_speed_vector();
    void set_position(int x, int y);
};

#endif /* BUBBLE_H_ */
