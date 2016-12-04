#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <string>
#include <vector>
#include "point2d.h"
#include "util.h"

typedef unsigned int uint;
typedef std::vector<std::string> map_row;
typedef std::vector<map_row> map;

class Board {
  public:
    Board();
    ~Board();
    void print_item_on_board(Point2d item);
    void print_board();
    bool is_a_hit_on_top_or_bottom_wall(Point2d item);
    int calculate_new_y(Point2d item);
    bool is_a_hit_on_left_or_right_wall(Point2d item);
    int calculate_new_x(Point2d item);
    void reset_board();

  private:
    static uint game_map_columns;
    static uint game_map_rows;
    map game_map;
};

#endif /* BOARD_H_ */
