#include "util.h"

int board_rows = 9;
int board_cols = 9;
int tile_width = 72;
int tile_height = 72;
int screen_width = board_cols * tile_width;
int screen_height = board_rows * tile_height;
int num_of_sceletons = 3;

std::string to_string(int integer) {
  std::stringstream x;
  x << integer;
  return x.str();
}

const int STEPS[15] = {3,3,3,4,4,4,4,5,5,5,5,5,5,6,6};
const int MAX_FLOORTILE_COUNT = int (0.62 * board_rows * board_cols);

void print_board(board myBoard) {
  for (uint i = 0; i < myBoard.size(); i++) {
    for (uint j = 0; j < myBoard[i].size(); j++) {
      std::cout << myBoard[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
