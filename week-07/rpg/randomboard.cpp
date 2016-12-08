#include "randomboard.h"

RandomBoard::RandomBoard(board &gameBoard) {
  filled_level = 0;
  direction = 0;
  draw_random_board(gameBoard);
}

void RandomBoard::draw_random_board(board &myBoard){
  int x = position.get_x();
  int y = position.get_y();
  if (x == 0 && y == 0 && !myBoard[x][y]) {
    myBoard[x][y] = 1;
    ++filled_level;
  }
  int steps = rand() % 15;
  int direction = rand() % 4; // 0-right, 1-up, 2-left, 3-down
  for (int i = 1; i <= STEPS[steps]; ++i){
    switch (direction) {
      case 0:
        step_right();
        break;
      case 1:
        step_up();
        break;
      case 2:
        step_left();
        break;
      default:
        step_down();
        break;
    }
    fill_with_floor(myBoard);
  }
  if (filled_level >= FILL_WITH_FLOOR){
    return;
  }
  draw_random_board(myBoard);
}

void RandomBoard::step_right(){
  int x = position.get_x();
  if (++x > board_cols - 1) {
    position.set_x(board_cols - 1);
    direction = rand() % 4;
    return;
  }
  position.set_x(x);
}

void RandomBoard::step_up(){
  int y = position.get_y();
  if (++y > board_rows - 1) {
    position.set_y(board_rows - 1);
    direction = rand() % 4;
    return;
  }
  position.set_y(y);
}

void RandomBoard::step_left(){
  int x = position.get_x();
  if (--x < 0) {
    position.set_x(0);
    direction = rand() % 4;
    return;
  }
  position.set_x(x);
}

void RandomBoard::step_down(){
  int y = position.get_y();
  if (--y < 0) {
    position.set_y(0);
    direction = rand() % 4;
    return;
  }
  position.set_y(y);
}

void RandomBoard::fill_with_floor(board &myBoard) {
  int x = position.get_x();
  int y = position.get_y();
  if(!myBoard[x][y]){
    ++filled_level;
    myBoard[x][y] = 1;
  }
}

void RandomBoard::print_board(board& gameBoard) {
  std::cout << "RandomBoard:" << std::endl;
  for (uint i = 0; i < gameBoard.size(); i++) {
    for (uint j = 0; j < gameBoard[i].size(); j++) {
      std::cout << gameBoard[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


