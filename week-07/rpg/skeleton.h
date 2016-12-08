#ifndef SKELETON_H_
#define SKELETON_H_
#include "killers.h"

class Skeleton : public Killers {
  public:
    Skeleton();
    Skeleton(const board &myBoard, const std::vector<Point2d> &killers_positions);
  private:
};

#endif /* SKELETON_H_ */
