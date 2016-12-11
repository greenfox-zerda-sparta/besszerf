#ifndef SKELETON_H_
#define SKELETON_H_
#include "killers.h"

class Skeleton : public Killers {
  public:
    Skeleton();
    Skeleton(const RandomBoard &myBoard, const std::vector<Killers*> &killers);
  private:
};

#endif /* SKELETON_H_ */
