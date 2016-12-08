#ifndef BOSS_H_
#define BOSS_H_
#include "killers.h"

class Boss : public Killers {
  public:
    Boss();
    Boss(const board &myBoard, const std::vector<Point2d> &killers_positions);
  private:
};

#endif /* BOSS_H_ */
