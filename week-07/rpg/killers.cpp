#include "killers.h"

Killers::Killers(const board &myBoard) {
  set_board(myBoard);
}

Killers::Killers(const board &myBoard, const std::vector<Point2d> &killers_positions) {
  set_board(myBoard);
  this->killers_positions = killers_positions;
  generate_random_position();
}

Killers::Killers() {}

Point2d Killers::get_position() {
  return position;
}

std::string Killers::get_image() {
  return image;
}

void Killers::set_board(board myBoard) {
  gameBoard = myBoard;
}

void Killers::move(GameContext& context) {}


void Killers::draw(GameContext& context) {
  context.draw_sprite(image, position.get_x(), position.get_y());
}

void Killers::generate_random_position() {
  Point2d _position;
  do {
    _position.set_x((rand() % board_cols) * tile_width);
    _position.set_y((rand() % board_rows) * tile_height);
  } while (!is_a_good_position(_position));
  position = _position;
}

bool Killers::is_a_good_position(Point2d &_position) {
  int x = _position.get_x()/tile_width;
  int y = _position.get_y()/tile_width;
  if (!gameBoard[x][y]) {
    return false;
  }
  for (uint i = 0; i < gameBoard.size(); i++) {
    if (killers_positions[i] == _position) {
      return false;
    }
  }
  return true;
}


