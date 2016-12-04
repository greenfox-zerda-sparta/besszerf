#include "board.h"

uint Board::game_map_rows = board_height;

uint Board::game_map_columns = board_width;

Board::Board() {
  game_map = map(game_map_rows, map_row(game_map_columns, "0"));
}

Board::~Board() {}

void Board::print_board() {
  std::cout << std::endl;
  for (uint row = 0; row < game_map_rows; row++) {
    for (uint column = 0; column < game_map_columns; column++) {
      std::cout << game_map[row][column] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void Board::print_item_on_board(Point2d item) {
  int y = item.get_x();
  int x = board_height -1 - item.get_y();
  if (game_map[x][y] == "0") {
    game_map[x][y] = "1";
    return;
  }
  int num_of_items_on_same_place = atoi(game_map[x][y].c_str()) + 1;
  game_map[x][y] = to_string(num_of_items_on_same_place);
}

void Board::reset_board() {
  game_map = map(game_map_rows, map_row(game_map_columns, "0"));
}

bool Board::is_a_hit_on_top_or_bottom_wall(Point2d item) {
  int y = item.get_y();
  if (y > (int)game_map_rows - 1 || y < 0) {
    return true;
  }
  return false;
}

int Board::calculate_new_y(Point2d item) {
  int y = item.get_y();
  int max_y_position = game_map_rows - 1;
  if (y > max_y_position) {
    return max_y_position + (max_y_position - item.get_y());
  }
  if (y < 0) {
    int min_y_position = 0;
    return min_y_position + (min_y_position - item.get_y());
  }
}

bool Board::is_a_hit_on_left_or_right_wall(Point2d item) {
  int x = item.get_x();
  if (x > (int)game_map_columns - 1 || x < 0) {
    return true;
  }
  return false;
}

int Board::calculate_new_x(Point2d item) {
  int x = item.get_x();
  int max_x_position = game_map_columns - 1;
  if (x > max_x_position) {
    return max_x_position + (max_x_position - item.get_x());
  }
  if (x < 0) {
    int min_x_position = 0;
    return min_x_position + (min_x_position - item.get_x());
  }
}

