#include "screendrawer.h"

void ScreenDrawer::draw_board(board& gameboard) {
  for (board::iterator it = gameboard.begin(); it != gameboard.end(); ++it) {
    for (row::iterator it2 = (*it).begin(); it2 != it->end(); ++it2) {
      std::cout << (int)*it2 << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}



