#include "Start_Window.h"

Start_Window::Start_Window() {
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_JPG);
  window = SDL_CreateWindow("Rubik's cube", 0, 30, 640, 480, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  surface = IMG_Load("startscreen.jpg");
  texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Start_Window::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}


Start_Window::~Start_Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}
