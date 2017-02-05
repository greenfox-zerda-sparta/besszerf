#pragma once
#include <vector>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Cube_Input {
private:
  vector<string> order = {"FRONT", "RIGHT", "BACK", "LEFT", "TOP", "DOWN"};
  vector<vector<int>> users_cube;
  vector<int> side;
  bool has_input;
  int shuffle;
public:
  Cube_Input();
  vector<vector<int>> vomit_users_vector();
  bool was_input();
  bool if_user_wants_input();
  void help();
  void get_input();
  void get_input_for_shuffle();
  void get_input_for_cube();
  void evaluate();
  int get_shuffle();
  ~Cube_Input();
};

