#include <iostream>
#include <utility>
#include <SDL.h>
#include "draw.h"

using namespace std;

class fractal_drawer {
  public:
    fractal_drawer();
    void draw_rectangle();
    void draw_fractal(int x);
    void set_renderer(SDL_Renderer* renderer);
  private:
    SDL_Renderer* renderer;
    draw d;
    pair<int, int> position;
    int phase;
    pair<int, int> original_position;
    pair<int, int> phase1_position;
    pair<int, int> phase2_position;
    pair<int, int> phase3_position;
    pair<int, int> phase4_position;
    int offset;


};
fractal_drawer::fractal_drawer() {
  phase = 1;
  offset = 600;
  original_position = make_pair(1, 1);
  position = original_position;
  renderer = NULL;
//  draw_rectangle();
}

void fractal_drawer::set_renderer(SDL_Renderer* renderer) {
  this->renderer = renderer;
}

void fractal_drawer::draw_rectangle () {
  d.MoveTo(position.first, position.second);
  d.DrawTo(renderer, position.first, position.second + offset);
  d.DrawTo(renderer, position.first + offset, position.second + offset);
  d.DrawTo(renderer, position.first + offset, position.second);
  d.DrawTo(renderer, position.first, position.second);

}

void fractal_drawer::draw_fractal(int x) {
  draw_rectangle();
  if (x == 0) {
    offset = 600;
    position.first = original_position.first;
    position.second = original_position.second;
    draw_rectangle();
    return;
  }
  if (phase == 1) {
    offset /= 3;
    position.first = original_position.first + offset;
    position.second = original_position.second;
    ++phase;
  } else if (phase == 2) {
    position.first = original_position.first;
    position.second = original_position.second + offset;
    ++phase;
  } else if (phase == 3) {
    position.first = original_position.first + 2*offset;
    position.second = original_position.second + offset;
    ++phase;
  } else if (phase == 4) {
    position.first =  original_position.first + offset;
    position.second = original_position.second + 2*offset;
    phase = 1;
    x -= 1;
  }
  draw_fractal(x);
}

void create_window(fractal_drawer drawer, int red, int green, int blue) {
  bool quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 603, 603, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  /*********************************************/
  drawer.set_renderer(renderer);
  /*********************************************/
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
    drawer.draw_fractal(6);
    /*********************************************/
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
 }

int main(int argc, char ** argv) {
  fractal_drawer drawer;
  create_window(drawer, 255, 255, 170);
 return 0;
}
