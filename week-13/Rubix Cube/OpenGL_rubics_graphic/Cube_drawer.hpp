#pragma once
#include <vector>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>
#include <utility>
#include <iostream>

class Cube_drawer {
private:
  GLuint texture;
  std::vector<GLuint> textures;
  std::vector<std::pair<int, int>> script;
  std::vector <std::pair<std::pair<int, int>, int>> cooord;
  
  float four_coord[40] = { 90.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 90.0, 1.0, 0.0, 0.0, 90.0, 0.0, 1.0, 0.0, 180.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  double scale_x;
  double scale_y;
  double scale_z;
public:
  Cube_drawer();
  ~Cube_drawer();
  void load_texture(char* file_name);
  void draw_square();
  void draw_flattened_cube(std::vector<int> &colors, int rubic_size);
  void draw_real_cube(std::vector<int> &colors, int rubic_size);
  void draw_background();
};