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
#include "bubble.h"
#include "util.h"

typedef unsigned int uint;
typedef std::vector<std::string> _row;
typedef std::vector<_row> _board;

template<class T>
class Board {
  private:
    _board game_map;
    std::vector<Bubble*> bubbles;
    Bubble* bubble;
    static uint game_map_columns;
    static uint game_map_rows;
    static uint wall_hits;
    void reset_board();
    void put_bubble_on_board();
  public:
    Board();
    void next_turn();
    void print_board();
    void move_bubble();
    uint get_wall_hits();
    Bubble get_bubble();

};

template<class T>
uint Board<T>::game_map_rows = board_height;

template<class T>
uint Board<T>::game_map_columns = board_width;

template<class T>
Board<T>::Board() {
  game_map = _board(game_map_rows, _row(game_map_columns, "0"));
  for (int i = 0; i < number_of_bubbles; i++) {
    std::cout << i << ". ";
    bubble = new Bubble();
    put_bubble_on_board();
    bubbles.push_back(bubble);
  }
  bubble = NULL;
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

template<class T>
void Board<T>::move_bubble() {
  wall_hits += bubble->move();
  put_bubble_on_board();
}

template<class T>
uint Board<T>::get_wall_hits() {
  return wall_hits;
}

template<class T>
Bubble Board<T>::get_bubble() {
  return *bubble;
}

template<class T>
void Board<T>::reset_board() {
  game_map = _board(game_map_rows, _row(game_map_columns, "0"));
}

template<class T>
void Board<T>::put_bubble_on_board() {
  int y = bubble->get_position().get_x();
  int x = board_height -1 - bubble->get_position().get_y();
  game_map[x][y] = "*";
}

template<class T>
void Board<T>::next_turn() {
    reset_board();
    for (int i = 0; i < number_of_bubbles; i++) {
      bubble = bubbles[i];
      move_bubble();
    }
    print_board();
}

#endif /* BOARD_HPP_ */
