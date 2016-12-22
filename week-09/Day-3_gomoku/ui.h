#ifndef UI_H_
#define UI_H_
#include <iostream>
#include <cstdlib>
#include <map>
#include "settings.h"
#include "game.h"

class UserInterface {
  public:
    virtual void run() = 0;
    virtual ~UserInterface();
  protected:
    Game* game;
    ScreenDrawer screen_drawer;

};



#endif /* UI_H_ */
