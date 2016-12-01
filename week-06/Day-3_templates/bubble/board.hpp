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
#include <cstdlib>
#include <sstream>

typedef unsigned int uint;
typedef std::vector<std::string> map_row;
typedef std::vector<map_row> map;

template<class T>
class Board {
  public:
    Board();
    ~Board();
    void print_board();
    void next_turn();
    uint get_wall_hits();
    uint get_collisions();
  private:
    static uint game_map_columns;
    static uint game_map_rows;
    static uint wall_hits;
    static uint collisions;
    map game_map;
    std::vector<Bubble*> bubbles;
    Bubble* bubble;
    void put_bubble_on_board();
    void reset_board();
    void move_bubble();
    bool is_a_wrong_position();

};

template<class T>
uint Board<T>::game_map_rows = board_height;

template<class T>
uint Board<T>::game_map_columns = board_width;

template<class T>
uint Board<T>::collisions = 0;

template<class T>
uint Board<T>::wall_hits = 0;

template<class T>
Board<T>::Board() {
  game_map = map(game_map_rows, map_row(game_map_columns, "0"));
  for (int i = 0; i < number_of_bubbles; i++) {
    std::cout << i << ". ";
    bubble = new Bubble();
    while (is_a_wrong_position()) {
      delete bubble;
      bubble = new Bubble();
    }
    put_bubble_on_board();
    bubbles.push_back(bubble);
  }
  bubble = NULL;
}

template<class T>
Board<T>::~Board() {
  for (int i = 0; i < number_of_bubbles; i++) {
    delete bubbles[i];
  }
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
void Board<T>::next_turn() {
    reset_board();
    for (int i = 0; i < number_of_bubbles; i++) {
      bubble = bubbles[i];
      move_bubble();
    }
    print_board();
}

template<class T>
uint Board<T>::get_wall_hits() {
  return wall_hits;
}

template<class T>
uint Board<T>::get_collisions() {
  return collisions;
}



template<class T>
void Board<T>::put_bubble_on_board() {
  int y = bubble->get_position().get_x();
  int x = board_height -1 - bubble->get_position().get_y();
  if (game_map[x][y] == "0") {
    game_map[x][y] = "1";
    return;
  } else if (game_map[x][y] == "1") {
    collisions++;
    std::cout << "New collision!" << std::endl;
  }
  int num_of_bubbles_on_same_place = atoi(game_map[x][y].c_str()) + 1;
  std::stringstream to_string;
  to_string << num_of_bubbles_on_same_place;
  game_map[x][y] = to_string.str();
}

template<class T>
void Board<T>::reset_board() {
  game_map = map(game_map_rows, map_row(game_map_columns, "0"));
}


template<class T>
void Board<T>::move_bubble() {
  wall_hits += bubble->move();
  put_bubble_on_board();
}

template<class T>
bool Board<T>::is_a_wrong_position() {
  for (uint i = 0; i < bubbles.size(); i++) {
    if (bubbles[i]->get_position() == bubble->get_position() ) {
      return true;
    }
  }
  return false;
}

#endif /* BOARD_HPP_ */
