#include "boss.h"

Boss::Boss() {
  image = "pics/boss.bmp";
}

Boss::Boss(const board &myBoard, const std::vector<Point2d> &killers_positions) : Killers (myBoard, killers_positions){
  image = "pics/boss.bmp";
}

