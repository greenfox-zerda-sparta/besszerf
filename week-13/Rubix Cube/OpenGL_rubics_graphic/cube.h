#pragma once

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;

class Cube {
private:
  vector<vector<int>> faces_of_cube;
  vector<int> up = { 4, 4, 4, 4, 4, 4, 4, 4, 4 }; // white 4
  vector<int> front = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // green 0
  vector<int> down = { 5, 5, 5, 5, 5, 5, 5, 5, 5 }; // yellow 5
  vector<int> back = { 2, 2, 2, 2, 2, 2, 2, 2, 2 }; // blue 2
  vector<int> right = { 1, 1, 1, 1, 1, 1, 1, 1, 1 }; // red 1
  vector<int> left = { 3, 3, 3, 3, 3, 3 ,3, 3, 3 }; // orange 3

  bool tr_back;

public:
  Cube();
  void random_shuffle();
  void random_shuffle(int);
  void rotate_front();
  void rotate_up();
  void rotate_back();
  void rotate_down();
  void rotate_right();
  void rotate_left();
  void draw_cube();
  void fill_faces_to_cube();
  bool is_ready();
  vector<int> get_vector_for_Lego();
  vector<char> trackback;
  void undo_last_step();
  ~Cube();
};

