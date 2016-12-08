#ifndef MYGAME_H_
#define MYGAME_H_
#include "gameengine2.hpp"
#include "point2d.h"
#include "util.h"
#include <vector>

typedef std::vector<bool> row;
typedef std::vector<row> board;

const int COVERABLE = int (0.62 * board_rows * board_cols);

class MyGame : public Game {
  public:
    MyGame();
    ~MyGame();
    void init(GameContext& context);
    void render(GameContext& context);
  private:
    board myBoard;
    Point2d hero_position;
    std::vector<Point2d> bad_boys_positions;
    int bad_boys_count;
    std::string hero_pic;
    Point2d set_badboy_position();
    void drawLevel(int x, int y, int covered);
    void print_board();
    void hero_move(GameContext& context);
    void set_hero_initial_position();
    Point2d generate_random_position();
    bool is_a_good_position(Point2d position);
};

#endif /* MYGAME_H_ */
