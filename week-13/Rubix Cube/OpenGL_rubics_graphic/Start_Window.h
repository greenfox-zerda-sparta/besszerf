#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Start_Window {
public:
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Surface* surface = NULL;
  SDL_Texture* texture = NULL;
public:
  Start_Window();
  void render();
  ~Start_Window();
};

