#ifndef RANDOMBOARD_H_
#define RANDOMBOARD_H_
#include <iostream>
#include <stdlib.h>
#include "gameengine2.hpp"
#include "point2d.h"
#include "util.h"
#include <vector>

typedef std::vector<bool> row;
typedef std::vector<row> board;

class RandomBoard {
  public:
    RandomBoard();
    board gameBoard;
    void print_board();
    void draw(GameContext& context);
    board get_board();
  private:
    Point2d position;
    int filled_level;
    int direction;
    void draw_random_playground_on_board();
    void step_right();
    void step_up();
    void step_left();
    void step_down();
    void fill_with_floor();
};

#endif /* RANDOMBOARD_H_ */
