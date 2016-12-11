#include "hero.h"

Hero::Hero() {
  image = "pics/hero-down.bmp";
  set_initial_position();
}

Hero::Hero(const RandomBoard &myBoard) : Killers (myBoard){
  image = "pics/hero-down.bmp";
  set_initial_position();
}

void Hero::set_initial_position() {
  for (uint i = 0; i < gameBoard->get_board().size(); i++) {
    for (uint j = 0; j < gameBoard->get_board()[i].size(); j++) {
      if (gameBoard->get_board()[i][j]) {
        position.set_y(i * tile_width);
        position.set_x(j * tile_height);
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
  if (y < board_rows - 1 && gameBoard->get_board()[y + 1][x]) {
    position.set_y(position.get_y() + tile_height);
    image = "pics/hero-down.bmp";
  }
}

void Hero::go_right() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (x < board_cols - 1 && gameBoard->get_board()[y][x + 1]) {
    position.set_x(position.get_x() + tile_width);
    image = "pics/hero-right.bmp";
  }
}

void Hero::go_up() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (y > 0 && gameBoard->get_board()[y - 1][x]) {
    position.set_y(position.get_y() - tile_height);
    image = "pics/hero-up.bmp";
  }
}

void Hero::go_left() {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_height;
  if (x > 0 && gameBoard->get_board()[y][x - 1]) {
    position.set_x(position.get_x() - tile_width);
    image = "pics/hero-left.bmp";
  }
}

