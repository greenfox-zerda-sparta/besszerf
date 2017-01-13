#ifndef UI_H_
#define UI_H_
#include <iostream>
#include <cstdlib>
#include <map>
#include "settings.h"
#include "game.h"

struct data_share {
    bool game_over;
    int player;
    coordinate coord;
    bool is_new_game_clicked;
    bool is_quit_clicked;
    int x;
    int y;
    bool quit;
    Game* game;
};

class UserInterface {
  public:
    virtual void run() = 0;
    virtual ~UserInterface();
};



#endif /* UI_H_ */
