#include <iostream>
#include <utility>
#include <SDL.h>
#include "draw.h"

using namespace std;

class fractal_drawer {
  public:
    fractal_drawer(SDL_Renderer* renderer);
    void draw_rectangle();
    void draw_fractal();
  private:
    SDL_Renderer* renderer;
    draw d;
    pair<int, int> position;
    int offset;


};
fractal_drawer::fractal_drawer(SDL_Renderer* renderer) {
  offset = 600;
  this->renderer = renderer;
  position = make_pair(1, 1);
  draw_rectangle();
}

void fractal_drawer::draw_rectangle () {
  d.MoveTo(position.first, position.second);
  d.DrawTo(renderer, position.first, position.second + offset);
  d.DrawTo(renderer, position.first + offset, position.second + offset);
  d.DrawTo(renderer, position.first + offset, position.second);
  d.DrawTo(renderer, position.first, position.second);

}

void fractal_drawer::draw_fractal() {
  offset /= 3;
  position.first = 1;
  draw_rectangle();
  position.first += offset;
  draw_rectangle();
  position.first += offset;
  draw_rectangle();
  if (position.first == 1+offset*2) {
    position.first = 1;
  }
  position.second += offset;
  draw_rectangle();
  position.first += offset;
  draw_rectangle();
  position.first += offset;
  draw_rectangle();
  if (position.first == 1+offset*2) {
    position.first = 1;
  }
  position.second += offset;
  draw_rectangle();
  position.first += offset;
  draw_rectangle();
  position.first += offset;
  draw_rectangle();
}

void create_window(int red, int green, int blue) {
  bool quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 603, 603, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, red, green, blue, 0);
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    /*********************************************/
    fractal_drawer drawer(renderer);
    drawer.draw_fractal();
    /*********************************************/
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
 }

int main(int argc, char ** argv) {
  create_window(255, 255, 170);
 return 0;
}
