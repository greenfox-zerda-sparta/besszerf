#include "screendrawer.h"

void ScreenDrawer::draw_board(const board& gameboard) {
  for (unsigned int i = 0; i < gameboard.size(); ++i) {
    for (unsigned int j = 0; j < gameboard[i].size(); ++j) {
      std::cout << (int)gameboard[j][gameboard[i].size() -1 -i] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

