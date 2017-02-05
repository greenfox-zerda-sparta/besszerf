#pragma once
#include "cube.h"

class Solver {
private:
  Cube* cube;
  vector<vector<int>> cube_v;
public:
  Solver(Cube* _cube);
  void solve_edges();
  void upper_l();
  void lower_l();
  void t();
  void little_l();
  void little_d();
  ~Solver();
};