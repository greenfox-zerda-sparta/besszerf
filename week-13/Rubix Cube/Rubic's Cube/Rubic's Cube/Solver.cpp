#include "Solver.h"

Solver::Solver(Cube* _cube) {
  this->cube = _cube;
  cube_v = cube->get_faces_of_cube();
}

void Solver::solve_edges() {
  cube_v = cube->get_faces_of_cube();
  if (cube_v[4][7] == 4 && cube_v[0][1] == 1) {
    upper_l();
  }
  if (cube_v[4][7] == 1 && cube_v[0][1] == 4) {
    little_l();
    upper_l();
    little_l();
    little_l();
    little_l();
  }
  if (cube_v[4][7] == 4 && cube_v[0][1] == 2) {
    t();
  }
  if (cube_v[4][7] == 2 && cube_v[0][1] == 4) {
    little_l();
    little_d();
    little_d();
    little_d();
    little_l();

    t();

    little_l();
    little_l();
    little_l();
    little_d();
    little_l();
    little_l();
    little_l();
  }
    if (cube_v[4][7] == 4 && cube_v[0][1] == 3) {
      lower_l();
    }
    if (cube_v[4][7] == 3 && cube_v[0][1] == 4) {
      little_l();
      little_l();
      little_l();
      upper_l();
      little_l();
    }
    if (cube_v[4][7] == 1 && cube_v[0][1] == 2) {
      cube->rotate_back();
      t();
      cube->rotate_back();
      cube->rotate_back();
      cube->rotate_back();
    }
    if (cube_v[4][7] == 2 && cube_v[0][1] == 1) {
      little_d();
      little_l();
      little_l();
      little_l();
      t();
      little_l();
      little_d();
      little_d();
      little_d();
    }
    if (cube_v[4][7] == 3 && cube_v[0][1] == 2) {
      cube->rotate_back();
      cube->rotate_back();
      cube->rotate_back();
      t();
      cube->rotate_back();
    }
    if (cube_v[4][7] == 2 && cube_v[0][1] == 3) {
      little_d();
      little_d();
      little_d();
      little_l();
      t();
      little_l();
      little_l();
      little_l();
      little_d();
    }
    if (cube_v[4][7] == 3 && cube_v[0][1] == 0) {
      little_d();
      little_d();
      little_l();
      t();
      little_l();
      little_l();
      little_l();
      little_d();
      little_d();
    }
    if (cube_v[4][7] == 0 && cube_v[0][1] == 3) {
      little_d();
      little_d();
      little_d();
      little_l();
      little_l();
      little_l();
      t();
      little_l();
      little_d();
    }
    if (cube_v[4][7] == 1 && cube_v[0][1] == 0) {
      little_d();
      little_d();
      little_l();
      little_l();
      little_l();
      t();
      little_l();
      little_d();
      little_d();
    }
    if (cube_v[4][7] == 0 && cube_v[0][1] == 1) {
      little_d();
      little_l();
      t();
      little_l();
      little_l();
      little_l();
      little_d();
      little_d();
      little_d();
    }
    if (cube_v[4][7] == 5 && cube_v[0][1] == 2) {
      cube->rotate_back();
      cube->rotate_back();
      t();
      cube->rotate_back();
      cube->rotate_back();
    }
    if (cube_v[4][7] == 2 && cube_v[0][1] == 5) {
      little_d();
      little_l();
      little_l();
      little_l();
      lower_l();
      little_l();
      little_d();
      little_d();
      little_d();
    }
    if (cube_v[4][7] == 5 && cube_v[0][1] == 3) {
      little_l();
      little_l();
      upper_l();
      little_l();
      little_l();
    }
    if (cube_v[4][7] == 3 && cube_v[0][1] == 5) {
      little_l();
      little_l();
      little_l();
      lower_l();
      little_l();
    }
    if (cube_v[4][7] == 5 && cube_v[0][1] == 0) {
      cube->rotate_down();
      cube->rotate_down();
      cube->rotate_back();
      cube->rotate_back();
      t();
      cube->rotate_back();
      cube->rotate_back();
      cube->rotate_down();
      cube->rotate_down();
    }
    if (cube_v[4][7] == 0 && cube_v[0][1] == 5) {
      little_d();
      little_d();
      little_d();
      little_l();
      little_l();
      little_l();
      lower_l();
      little_l();
      little_d();
    }
    if (cube_v[4][7] == 5 && cube_v[0][1] == 1) {
      little_l();
      little_l();
      lower_l();
      little_l();
      little_l();
    }
    if (cube_v[4][7] == 1 && cube_v[0][1] == 5) {
      little_l();
      upper_l();
      little_l();
      little_l();
      little_l();
    }
    if (cube_v[4][7] == 0 && cube_v[0][1] == 4) {
    
    }
    if (cube_v[4][7] == 4 && cube_v[0][1] == 0) {

    }
  }

void Solver::upper_l() {
  cube->rotate_back();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_back();
  cube->rotate_back();
  cube->rotate_back();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
}

void Solver::lower_l() {
  cube->rotate_back();
  cube->rotate_back();
  cube->rotate_back();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_back();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
}

void Solver::t() {
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_up();

  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_left();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_up();
  cube->rotate_up();

  cube->rotate_front();
  cube->rotate_up();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_front();
  cube->rotate_left();
  cube->rotate_left();
  cube->rotate_left();
}

void Solver::little_l() {
  cube->rotate_back();
  cube->rotate_middle_rw();
}

void Solver::little_d() {
  cube->rotate_down();
  cube->rotate_middle_gr();
}

Solver::~Solver() {}