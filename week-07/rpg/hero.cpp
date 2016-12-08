#include "hero.h"

Hero::Hero() {
  image = "pics/hero-down.bmp";
  set_initial_position();
}

Hero::Hero(const board &myBoard) : Killers (myBoard){
  image = "pics/hero-down.bmp";
  set_initial_position();
}

void Hero::set_initial_position() {
  for (uint i = 0; i < gameBoard.size(); i++) {
    for (uint j = 0; j < gameBoard[i].size(); j++) {
      if (gameBoard[i][j]) {
        position.set_x(i * tile_width);
        position.set_y(j * tile_height);
        return;
      }
    }
  }
}

void Hero::move(GameContext& context) {
  if (context.was_key_pressed(ARROW_DOWN)) {
    go_down();
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    go_right();
  }
  if (context.was_key_pressed(ARROW_UP)) {
    go_up();
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    go_left();
  }
}
void Hero::go_down() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (y < board_rows - 1 && gameBoard[x][y + 1]) {
    position.set_y(position.get_y() + tile_height);
    image = "pics/hero-down.bmp";
  }
}

void Hero::go_right() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (x < board_cols - 1 && gameBoard[x + 1][y]) {
    position.set_x(position.get_x() + tile_width);
    image = "pics/hero-right.bmp";
  }
}

void Hero::go_up() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (y > 0 && gameBoard[x][y - 1]) {
    position.set_y(position.get_y() - tile_height);
    image = "pics/hero-up.bmp";
  }
}

void Hero::go_left() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (x > 0 && gameBoard[x - 1][y]) {
    position.set_x(position.get_x() - tile_width);
    image = "pics/hero-left.bmp";
  }
}

