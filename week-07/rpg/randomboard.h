#ifndef RANDOMBOARD_H_
#define RANDOMBOARD_H_
#include <iostream>
#include <stdlib.h>
#include "point2d.h"
#include "util.h"
#include <vector>

typedef std::vector<bool> row;
typedef std::vector<row> board;

class RandomBoard {
  public:
    RandomBoard(board &gameBoard);
  private:
    Point2d position;
    int filled_level;
    int direction;
    void print_board(board& gameBoard);
    void draw_random_board(board &gameBoard);
    void step_right();
    void step_up();
    void step_left();
    void step_down();
    void fill_with_floor(board &gameBoard);
};



#endif /* RANDOMBOARD_H_ */
