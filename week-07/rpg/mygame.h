#ifndef MYGAME_H_
#define MYGAME_H_
#include "gameengine2.hpp"
#include "point2d.h"
#include "util.h"
#include <vector>

typedef std::vector<bool> row;
typedef std::vector<row> board;

const int COVERABLE = int (0.54 * board_rows * board_cols);

class MyGame : public Game {
  public:
    MyGame();
    ~MyGame();
    void init(GameContext& context);
    void render(GameContext& context);
  private:
    board myBoard;
    Point2d hero_position;
    std::string hero_pic(GameContext& context);
    void drawLevel(int x, int y, int covered);
    void print_board();
    void hero_move(GameContext& context);
};

#endif /* MYGAME_H_ */
