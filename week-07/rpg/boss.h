#ifndef BOSS_H_
#define BOSS_H_
#include "killers.h"

class Boss : public Killers {
  public:
    Boss();
    Boss(const RandomBoard &myBoard, const std::vector<Killers*> &killers_positions);
  private:
};

#endif /* BOSS_H_ */
