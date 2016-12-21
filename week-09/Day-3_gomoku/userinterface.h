#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include "game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class UserInterface {
  public:
    UserInterface(Game& game);
    ~UserInterface();
    void run();
  private:
    Game* game;
};
#endif /* USERINTERFACE_H_ */

