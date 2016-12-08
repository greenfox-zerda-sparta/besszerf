#include "skeleton.h"

Skeleton::Skeleton() {
  image = "pics/skeleton.bmp";
}

Skeleton::Skeleton(const board &myBoard, const std::vector<Point2d> &killers_positions) : Killers (myBoard, killers_positions){
  image = "pics/skeleton.bmp";
}

