#ifndef MYGAME_H_
#define MYGAME_H_
#include "gameengine2.hpp"
#include "util.h"
#include <vector>

typedef std::vector<int> row;
typedef std::vector<row> board;

class MyGame : public Game {
  public:
    MyGame();
    ~MyGame();
    virtual void init(GameContext& context);
    virtual void render(GameContext& context);
  private:
    board myBoard;
};

#endif /* MYGAME_H_ */
