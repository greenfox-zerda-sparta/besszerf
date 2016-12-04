#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_
#include <iostream>
#include "bubble.h"
#include "board.h"
#include <sstream>
#include <exception>

template<class T, class P>
class Application {
  public:
    Application();
    ~Application();
    int run();
  private:
    P* gameboard;
    std::vector<T*> item_container;
    uint collisions;
    uint wallhits;
    void init_game();
    void new_turn();
    void print_statistics();
    void init_item_container();
    bool is_a_wrong_position(int item_position);
    void update_board();
    void print_board();
    void move_items();
    void move_one_item(T* item);
    void update_collisions();
    bool is_a_former_collision(Point2d position, std::vector<Point2d> &temp_collisions);
};

template<class T, class P>
Application<T, P>::Application() {
  gameboard = new P();
  collisions = 0;
  wallhits = 0;
  item_container = std::vector<T*>(number_of_items);
}

template<class T, class P>
Application<T, P>::~Application() {
  delete gameboard;
  for (uint i = 0; i < item_container.size(); i++) {
    delete item_container[i];
  }
}

template<class T, class P>
int Application<T, P>::run(){
  try {
    init_game();
    for (int i = 0; i < num_of_turns; i++) {
      new_turn();
    }
    print_statistics();
    return 0;
  } catch (const char** e) {
    std::cout << e << std::endl;
    return 1;
  }
}

template<class T, class P>
void Application<T, P>::init_game() {
  init_item_container();
  update_board();
  print_board();
}

template<class T, class P>
void Application<T, P>::init_item_container() {
  for (int i = 0; i < number_of_items; i++) {
    std::cout << i << ". ";
    item_container[i] = new T();
    while (is_a_wrong_position(i)) {
      delete item_container[i];
      item_container[i] = new T();
    }
  }
}

template<class T, class P>
bool Application<T, P>::is_a_wrong_position(int item_pos) {
  Point2d ref_position = item_container[item_pos]->get_position();
  for (int i = 0; i < item_pos; i++) {
    if (item_container[i]->get_position() == ref_position) {
      return true;
    }
  }
  return false;
}

template<class T, class P>
void Application<T, P>::update_board() {
  gameboard->reset_board();
  for (int i = 0; i < number_of_items; i++) {
    gameboard->print_item_on_board(item_container[i]->get_position());
  }
}

template<class T, class P>
void Application<T, P>::print_board() {
  gameboard->print_board();
}

template<class T, class P>
void Application<T, P>::new_turn() {
  move_items();
  update_board();
  print_board();
  update_collisions();
}

template<class T, class P>
void Application<T, P>::move_items() {
  for (int i = 0; i < number_of_items; i++) {
    move_one_item(item_container[i]);
  }
}

template<class T, class P>
void Application<T, P>::move_one_item(T* item) {
  Point2d next_position = item->get_next_position();
  if (gameboard->is_a_hit_on_top_or_bottom_wall(next_position) ) {
    wallhits++;
    item->turn_vertically();
    next_position.set_y(gameboard->calculate_new_y(next_position));
  }
  if (gameboard->is_a_hit_on_left_or_right_wall(next_position) ) {
    wallhits++;
    item->turn_horizontally();
    next_position.set_x(gameboard->calculate_new_x(next_position));
  }
  item->move(next_position);
}

template<class T, class P>
void Application<T, P>::update_collisions() {
  std::vector<Point2d> temp_collisions;
  for (int i = 0; i < number_of_items - 1; i++) {
    Point2d position = item_container[i]->get_position();
    for (int j = i + 1; j < number_of_items; j++) {
      if (position == item_container[j]->get_position()) {
        if (!is_a_former_collision(position, temp_collisions)) {
          temp_collisions.push_back(position);
          collisions++;
          break;
        }
      }
    }
  }
}

template<class T, class P>
bool Application<T, P>::is_a_former_collision(Point2d position, std::vector<Point2d> &temp_collisions) {
  for (uint k = 0; k < temp_collisions.size(); k++) {
    if (position == temp_collisions[k]) {
      return true;
    }
  }
  return false;
}

template<class T, class P>
void Application<T, P>::print_statistics() {
  std::cout << "During " << num_of_turns << " turns:" << std::endl;
  std::cout << "   Bubbles hit the wall: " << wallhits << " times."<< std::endl;
  std::cout << "   Collisions: " << collisions << std::endl;
}

#endif /* APPLICATION_HPP_ */
