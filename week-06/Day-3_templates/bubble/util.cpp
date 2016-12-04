#include "util.h"

int board_height = 10;
int board_width = 10;
int number_of_items = 10;
int move_units_max = 3;
int num_of_turns = 10;

std::string to_string(int i) {
  std::stringstream to_string;
  to_string << i;
  return to_string.str();
}
