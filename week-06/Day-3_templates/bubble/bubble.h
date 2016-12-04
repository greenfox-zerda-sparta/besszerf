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
    void move(Point2d new_position);
    Point2d get_position();
    Point2d get_next_position();
    void turn_horizontally();
    void turn_vertically();
  private:
    Point2d position;
    Point2d speed_vector;
};

#endif /* BUBBLE_H_ */
