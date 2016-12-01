/*
 * board.h
 *
 *  Created on: 2016.12.01.
 *      Author: caruzzo74
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_
#include <string>
#include <vector>
#include <iostream>

typedef unsigned int uint;
typedef std::vector<std::string> _row;
typedef std::vector<_row> _board;

template<class T>
class Board {
  private:
    _board game_map;
    static uint game_map_columns;
    static uint game_map_rows;
    static uint wall_hits;
  public:
    Board();
    void print_board();

};

template<class T>
uint Board<T>::game_map_rows = 10;

template<class T>
uint Board<T>::game_map_columns = 10;

template<class T>
Board<T>::Board() {
    game_map = _board(game_map_rows, _row(game_map_columns, "0"));
}

template<class T>
void Board<T>::print_board() {
  for (uint row = 0; row < game_map_rows; row++) {
    for (uint column = 0; column < game_map_columns; column++) {
      std::cout << game_map[row][column];
    }
    std::cout << std::endl;
  }
}

template<class T>
uint Board<T>::wall_hits = 0;


#endif /* BOARD_HPP_ */
