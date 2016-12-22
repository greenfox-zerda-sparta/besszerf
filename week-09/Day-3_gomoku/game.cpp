#include "game.h"

Game::Game() {
  gameboard = board(board_col_size, row(board_row_size, board_sign));
  player1 = {1, p1_sign};
  player2 = {2, p2_sign};
  current_player = &player1;
}

Game::~Game() {}

void Game::set_next_player() {
  current_player = (current_player == &player1)? &player2 : &player1;
}

bool Game::next_turn(coordinate coord) {
  if (!is_not_engaged(coord)) {
    set_board(coord);
    if (!has_current_player_won(coord)) {
      set_next_player();
    } else {
      return false;
    }
  }
  return true;
}

bool Game::is_not_engaged(coordinate& coord) {
  if (gameboard[coord.first][coord.second] == 0) {
    return false;
  }
  return true;
}

void Game::set_board(coordinate& coord) {
  gameboard[coord.first][coord.second] = current_player->sign;
}

bool Game::has_current_player_won(coordinate& coord) {
  if (winner_checker.is_a_winner_line(gameboard, coord, current_player)) {
    return true;
  }
  return false;
}

Player Game::get_current_player() {
  return *current_player;
}
/*
board Game::get_board() {
  return gameboard;
}
*/
void Game::reset() {
  gameboard = board(board_col_size, row(board_row_size, board_sign));
  player1 = {1, p1_sign};
  player2 = {2, p2_sign};
  current_player = &player1;
}

