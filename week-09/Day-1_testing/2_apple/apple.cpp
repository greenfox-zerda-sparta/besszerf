#include "apple.h"

string Apple::get_apple() {
  return "Apple";
}

int Apple::sum_apples(vector<int>& apples_on_shelves) {
  int sum = 0;
  for (unsigned int i = 0; i < apples_on_shelves.size(); ++i) {
    sum += apples_on_shelves[i];
  }
  return sum;
}
