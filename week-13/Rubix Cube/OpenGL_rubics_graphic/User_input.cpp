#include "User_input.hpp"


User_input::User_input() : WINDOW_WIDTH(0), WINDOW_HEIGHT(0) {
  this->changing_x = 0;
  this->changing_y = 0;
  this->changing_mouse_x = 0;
  this->changing_mouse_y = 0;
  this->step = 1;

  this->angle_x = 0;
  this->angle_z = 0;
  this->repeat = 1;

}

User_input::User_input(int width, int height) : WINDOW_WIDTH(width), WINDOW_HEIGHT(height) {
  this->changing_x = 0;
  this->changing_y = 0;
  this->changing_mouse_x = 0;
  this->changing_mouse_y = 0;
  this->step = 1;

  this->angle_x = 0;
  this->angle_z = 0;
  this->repeat = 1;

}

void User_input::input_handler(bool& running, Cube& _cube) {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_RIGHT:
        break;
      case SDLK_LEFT:
        break;
      case SDLK_UP:
        break;
      case SDLK_DOWN:
        break;
      case SDLK_f:
        _cube.rotate_front();
        break;
      case SDLK_u:
        _cube.rotate_up();
        break;
      case SDLK_b:
        _cube.rotate_back();
        break;
      case SDLK_d:
        _cube.rotate_down();
        break;
      case SDLK_l:
        _cube.rotate_right();
        break;
      case SDLK_r:
        _cube.rotate_left();
        break;
      case SDLK_SPACE:
        _cube.random_shuffle();
        break;
      case SDLK_s:
        while (true) {
          _cube.undo_last_step();
          if (_cube.trackback.empty()) {
            break;
          }
        }
        break;
      case SDLK_BACKSPACE:
        _cube.undo_last_step();
        break;
      case SDLK_ESCAPE:
        running = false;
        break;
      }
      break;
    case SDL_MOUSEMOTION:
      this->angle_z = event.motion.x + WINDOW_WIDTH * 0.5;
      this->angle_x = event.motion.y + WINDOW_HEIGHT * 0.5;
      break;
    }
  }
}

int User_input::get_changing_x() {
  return this->changing_x;
}

int User_input::get_changing_y() {
  return this->changing_y;
}

int User_input::get_changing_mouse_x() {
  return this->changing_mouse_x;
}

int User_input::get_changing_mouse_y() {
  return this->changing_mouse_y;
}

int User_input::get_repeat() {
  return this->repeat;
}

double User_input::get_angle_x() {
  return this->angle_x;
}

double User_input::get_angle_z() {
  return this->angle_z;
}

void User_input::set_step(int _value) {
  this->step = _value;
}

User_input::~User_input() {
}