#ifndef MYGAME_H_
#define MYGAME_H_
#include "randomboard.h"
#include "hero.h"
#include "boss.h"
#include "skeleton.h"
#include <vector>

class MyGame : public Game {
  public:
    MyGame();
    ~MyGame();
    void init(GameContext& context);
    void render(GameContext& context);
  private:
    void init_killers();
    RandomBoard gameBoard;
    std::vector<Killers*> faces;
};

#endif /* MYGAME_H_ */
