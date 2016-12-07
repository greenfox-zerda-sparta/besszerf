#include "util.h"

int board_rows = 10;
int board_cols = 10;
int tile_width = 72;
int tile_height = 72;
int screen_width = board_cols * tile_width;
int screen_height = board_rows * tile_height;

std::string to_string(int integer) {
  std::stringstream x;
  x << integer;
  return x.str();
}

const int STEPS[15] = {3,3,4,5,4,4,4,5,5,5,5,5,6,6,6};

