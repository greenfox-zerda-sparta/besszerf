#ifndef HERO_H_
#define HERO_H_
#include "killers.h"

class Hero : public Killers {
  public:
    Hero();
    Hero(const RandomBoard &myBoard);
    void move(GameContext& context);
  private:
    void set_initial_position();
    void go_down();
    void go_up();
    void go_left();
    void go_right();
};

#endif /* HERO_H_ */
