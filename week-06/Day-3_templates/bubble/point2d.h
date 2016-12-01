/*
 * point2d.h
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */

#ifndef POINT2D_H_
#define POINT2D_H_

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

#endif /* POINT2D_H_ */
