#ifndef __FERI
#pragma once
#include <SDL.h>
#include <iostream>

class User_input {
private:
  SDL_Event event;
  const int WINDOW_WIDTH;
  const int WINDOW_HEIGHT;
  int changing_x;
  int changing_y;
  int changing_mouse_x;
  int changing_mouse_y;
  int step;
  double angle_x;
  double angle_z;
  int repeat;
public:
  User_input();
  User_input(int width, int height);
  void input_handler(bool& running);
  int get_changing_x();
  int get_changing_y();
  int get_changing_mouse_x();
  int get_changing_mouse_y();
  int get_repeat();
  double get_angle_x();
  double get_angle_z();
  void set_step(int _value);
  ~User_input();
};

#endif
