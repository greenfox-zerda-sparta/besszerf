#include "skeleton.h"

Skeleton::Skeleton() {
  image = "pics/skeleton.bmp";
}

Skeleton::Skeleton(const RandomBoard &myBoard, const std::vector<Killers*> &killers) : Killers (myBoard, killers){
  image = "pics/skeleton.bmp";
}

