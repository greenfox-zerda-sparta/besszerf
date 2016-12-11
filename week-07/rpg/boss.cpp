#include "boss.h"

Boss::Boss() {
  image = "pics/boss.bmp";
}

Boss::Boss(const RandomBoard &myBoard, const std::vector<Killers*> &killers) : Killers (myBoard, killers){
  image = "pics/boss.bmp";
}

