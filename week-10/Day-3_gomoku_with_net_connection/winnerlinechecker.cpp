#include "winnerlinechecker.h"

WinnerLineChecker::WinnerLineChecker() {
  winner_item_count = 1;
  can_count_to_negative_direction = true;
  can_count_to_positive_direction = true;
  negative_vector = {0, 0};
  positive_vector = negative_vector;
  current_player = 0;
  
}

WinnerLineChecker::~WinnerLineChecker() {}

void WinnerLineChecker::reset() {
  winner_item_count = 1;
  can_count_to_negative_direction = true;
  can_count_to_positive_direction = true;
}

bool WinnerLineChecker::is_a_winner_line(board& gameboard, coordinate& coord, Player* current_player) {
  this->current_player = current_player;
  if (is_a_winner_line_horizontally(gameboard, coord)) {return true;}
  if (is_a_winner_line_vertically(gameboard, coord)) {return true;}
  if (is_a_winner_line_from_left_to_down(gameboard, coord)) {return true;}
  if (is_a_winner_line_from_right_to_down(gameboard, coord)) {return true;}
  return false;
}

bool WinnerLineChecker::is_a_winner_line_horizontally(board& gameboard, coordinate& coord) {
  reset();
  negative_vector.first = -1;
  negative_vector.second = 0;
  positive_vector.first = 1;
  positive_vector.second = 0;
  return run_winner_searching_cycle(gameboard, coord);
}

bool WinnerLineChecker::is_a_winner_line_vertically(board& gameboard, coordinate& coord) {
  reset();
  negative_vector.first = 0;
  negative_vector.second = -1;
  positive_vector.first = 0;
  positive_vector.second = 1;
  return run_winner_searching_cycle(gameboard, coord);
}

bool WinnerLineChecker::is_a_winner_line_from_left_to_down(board& gameboard, coordinate& coord) {
  reset();
  negative_vector.first = -1;
  negative_vector.second = -1;
  positive_vector.first = 1;
  positive_vector.second = 1;
  return run_winner_searching_cycle(gameboard, coord);
}

bool WinnerLineChecker::is_a_winner_line_from_right_to_down(board& gameboard, coordinate& coord) {
  reset();
  negative_vector.first = 1;
  negative_vector.second = -1;
  positive_vector.first = -1;
  positive_vector.second = 1;
  return run_winner_searching_cycle(gameboard, coord);
}

bool WinnerLineChecker::run_winner_searching_cycle(board& gameboard, coordinate& coord) {
  coordinate neg_coord_in_cycle = coord;
  coordinate pos_coord_in_cycle = coord;
  do {
    if(can_count_to_negative_direction) {
      count_to_negative_direction(gameboard, neg_coord_in_cycle);
    }
    if(can_count_to_positive_direction) {
      count_to_positive_direction(gameboard, pos_coord_in_cycle);
    }
  } while((can_count_to_negative_direction || can_count_to_positive_direction) && winner_item_count < 5);
    if (winner_item_count > 4) {
      return true;
  }
  return false;

}

void WinnerLineChecker::count_to_negative_direction(board& gameboard, coordinate& neg_coord_in_cycle) {
  if(is_a_winner_sign_backwards(gameboard, neg_coord_in_cycle)) {
    ++winner_item_count;
  } else {
    can_count_to_negative_direction = false;
  }
}

void WinnerLineChecker::count_to_positive_direction(board& gameboard, coordinate& pos_coord_in_cycle) {
  if(is_a_winner_sign_towards(gameboard, pos_coord_in_cycle)) {
    ++winner_item_count;
  } else {
    can_count_to_positive_direction = false;
  }
}

bool WinnerLineChecker::is_a_winner_sign_backwards(board& gameboard, coordinate& neg_coord_in_cycle) {
  if (!is_a_wallhit_in_negative_direction(neg_coord_in_cycle)) {
    decrement_negative_coordinate_in_cycle(neg_coord_in_cycle);
    if (gameboard[neg_coord_in_cycle.first][neg_coord_in_cycle.second] == current_player->sign) {
      return true;
    }
  }
  return false;
}

bool WinnerLineChecker::is_a_winner_sign_towards(board& gameboard, coordinate& pos_coord_in_cycle) {
  if (!is_a_wallhit_in_positive_direction(pos_coord_in_cycle)) {
    increment_positive_coordinate_in_cycle(pos_coord_in_cycle);
    if (gameboard[pos_coord_in_cycle.first][pos_coord_in_cycle.second] == current_player->sign) {
      return true;
    }
  }
  return false;
}

bool WinnerLineChecker::is_a_wallhit_in_negative_direction(coordinate& neg_coord_in_cycle) {
  if(neg_coord_in_cycle.first + negative_vector.first > -1
      && neg_coord_in_cycle.second + negative_vector.second > -1
      && neg_coord_in_cycle.first + negative_vector.first < board_col_size) {
    return false;
  }
  return true;
}
    ;
bool WinnerLineChecker::is_a_wallhit_in_positive_direction(coordinate& pos_coord_in_cycle) {
  if(pos_coord_in_cycle.first + positive_vector.first < board_col_size
      && pos_coord_in_cycle.second + positive_vector.second < board_col_size
      && pos_coord_in_cycle.first + positive_vector.first > -1) {
    return false;
  }
  return true;
}


void WinnerLineChecker::decrement_negative_coordinate_in_cycle(coordinate& neg_coord_in_cycle) {
  neg_coord_in_cycle.first += negative_vector.first;
  neg_coord_in_cycle.second += negative_vector.second;
}

void WinnerLineChecker::increment_positive_coordinate_in_cycle(coordinate& pos_coord_in_cycle) {
  pos_coord_in_cycle.first += positive_vector.first;
  pos_coord_in_cycle.second += positive_vector.second;
}

