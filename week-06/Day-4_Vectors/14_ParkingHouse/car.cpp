#include <string>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
#include "car.h"

using namespace std;

std::vector<std::string> Car::used_plates;

Car::Car() {
  type = types[rand() %18];
  color = colors[rand() %10];
  plate_num = get_new_plate();
}
string Car::get_type() {
  return type;
}

string Car::get_color() {
  return color;
}

string Car::get_platenum() {
  return plate_num;
}

string Car::get_new_plate() {
  string platenum;
  do {
    platenum = "";
    for (int i = 0; i < 3; i++) {
      platenum += (rand() %26) + 65;
    }
    platenum += "-";
    for (int i = 0; i < 3; i++) {
      platenum += (rand() %10) + 48;
    }
  } while (is_used(platenum));
  return platenum;
}

bool Car::is_used(std::string platenum) {
  uint vec_size = used_plates.size();
  if (vec_size != 0) {
    for (uint i = 0; i < vec_size; i++) {
      if (used_plates[i] == platenum) {
        return true;
      }
    }
  }
  used_plates.push_back(platenum);
  return false;
}
