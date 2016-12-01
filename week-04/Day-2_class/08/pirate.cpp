#include <iostream>
#include <string>
#include "pirate.h"

using namespace std;

Pirate::Pirate() {
  this->drinked_rums = 0;
}
void Pirate::drink_rum() {
  this->drinked_rums += 1;
}
string Pirate::hows_goin_mate() {
  return (this->drinked_rums > 4 ? "Arrrr!" : "Nothin!");
}
