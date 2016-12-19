#include "SDL_environment.h"


SDL_environment::SDL_environment(const char* window_title,
                                        unsigned int screen_width,
                                        unsigned int screen_height) {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(window_title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    screen_width, screen_height, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  reset_keys();
}

SDL_environment::~SDL_environment() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SDL_environment::init(color background, color draw_color) {
  SDL_SetRenderDrawColor(renderer, background.red, background.green, background.blue, 0);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, draw_color.red, draw_color.green, draw_color.blue, 255);
}

void SDL_environment::render() {
  SDL_RenderPresent(renderer);
}

void SDL_environment::reset_keys() {
  for (unsigned int i = 0; i < 5; ++i) {
    keys[i] = false;
  }
}

void SDL_environment::on_key_down(unsigned int key_code) {
  keys[key_code] = true;
}

bool SDL_environment::was_key_pressed(unsigned int key_code) {
  return keys[key_code];
}

void SDL_environment::MoveTo(int x, int y) {
  drawer.MoveTo(x, y);
}

void SDL_environment::DrawTo(int x, int y) {
  drawer.DrawTo(renderer, x, y);
}
