#ifndef MYGAME_H_
#define MYGAME_H_
#include "gameengine2.hpp"
#include "util.h"
#include <vector>

typedef std::vector<bool> row;
typedef std::vector<row> board;

const int COVERABLE = 54;

class MyGame : public Game {
  public:
    MyGame();
    ~MyGame();
    void init(GameContext& context);
    void render(GameContext& context);
  private:
    board myBoard;
    void drawLevel(int x, int y, int covered);
};

#endif /* MYGAME_H_ */
