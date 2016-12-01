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

class Point2d {
  private:
    int x;
    int y;
  public:
    void set_x(int x);
    void set_y(int y);
    int get_x();
    int get_y();
};

class Bubble {
  private:
    Point2d position;
    Point2d speed_vector;
  public:
    Bubble();
    void move();
    Point2d get_position();
    Point2d get_speed_vector();
    void set_position(int x, int y);
};

#endif /* BUBBLE_H_ */
