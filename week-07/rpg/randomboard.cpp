#include "randomboard.h"

RandomBoard::RandomBoard() {
  gameBoard = board(board_rows, row(board_cols, 0));
  gameBoard[0][0] = 1;
  filled_level = 0;
  direction = 0;
  draw_random_playground_on_board();
}

void RandomBoard::draw_random_playground_on_board(){
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
    fill_with_floor();
  }
  if (filled_level >= MAX_FLOORTILE_COUNT){
    return;
  }
  draw_random_playground_on_board();
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

void RandomBoard::step_down(){
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

void RandomBoard::step_up(){
  int y = position.get_y();
  if (--y < 0) {
    position.set_y(0);
    direction = rand() % 4;
    return;
  }
  position.set_y(y);
}

void RandomBoard::fill_with_floor() {
  int x = position.get_x();
  int y = position.get_y();
  if(!gameBoard[y][x]){
    ++filled_level;
    gameBoard[y][x] = 1;
  }
}

void RandomBoard::draw(GameContext& context) {
  for (uint i = 0; i < gameBoard.size(); i++) {
    uint y = i * tile_width;
    for (uint j = 0; j < gameBoard[i].size(); j++) {
      uint x = j * tile_height;
      context.draw_sprite((gameBoard[i][j]?"pics/floor.bmp":"pics/wall.bmp"), x, y);
    }
  }
}

const board RandomBoard::get_board() const {
  return gameBoard;
}
