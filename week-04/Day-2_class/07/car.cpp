#include <iostream>
#include <string>

#include "car.h"

using namespace std;

Car::Car(string type, int km) {
  this->type = type;
  this->km = km;
}

void Car::run(int km) {
  this->km += km;
}

const int Car::get_km() {
  return this->km;
}