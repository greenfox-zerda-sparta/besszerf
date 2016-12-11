#include "killers.h"

//std::vector<Killers*> Killers::killers;
const RandomBoard* Killers::gameBoard;

Killers::Killers(const RandomBoard &myBoard) {
  if (gameBoard == NULL) {
    gameBoard = &myBoard;
  }
}

Killers::Killers(const RandomBoard &myBoard, const std::vector<Killers*> &killers) {
  if (gameBoard == NULL) {
    gameBoard = &myBoard;
  }
  generate_random_position(killers);
}

Killers::Killers() {}

void Killers::move(GameContext& context) {}

void Killers::draw(GameContext& context) {
  context.draw_sprite(image, position.get_x(), position.get_y());
}

void Killers::generate_random_position(const std::vector<Killers*> &killers) {
  Point2d _position;
  do {
    _position.set_x((rand() % board_cols) * tile_width);
    _position.set_y((rand() % board_rows) * tile_height);
  } while (!is_a_good_position(_position, killers));
  position = _position;
}

bool Killers::is_a_good_position(Point2d &_position, const std::vector<Killers*> &killers) {
  int x = _position.get_x()/tile_width;
  int y = _position.get_y()/tile_width;
  if (!gameBoard->get_board()[y][x]) {
    return false;
  }
  for (uint i = 0; i < killers.size(); i++) {
    if (killers[i]->position == _position) {
      return false;
    }
  }
  return true;
}

