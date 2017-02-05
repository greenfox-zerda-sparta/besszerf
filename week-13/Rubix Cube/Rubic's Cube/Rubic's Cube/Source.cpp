#include "cube.h"
//#include "Cube_Input.h"
#include "../Start_Window.h"

bool is_inside(int x, int y, SDL_Rect current) {
  if (x < current.x) {
    return false;
  }
  else if (x > current.x + current.w) {
    return false;
  }
  else if (y < current.y) {
    return false;
  }
  else if (y > current.y + current.h) {
    return false;
  }
  return true;
}

int which_button(int x, int y, vector<SDL_Rect> buttons) {
  for (int i = 0; i < buttons.size(); i++) {
    SDL_Rect current = buttons[i];
    if (is_inside(x, y, current)) {
      return i;
    }
  }
}

int main(int argc, char* argv[]) {
  Start_Window swin;
  SDL_Event event;
  vector<SDL_Rect> buttons;
  SDL_Rect easy = { 40, 130, 150, 50 };
  buttons.push_back(easy);
  SDL_Rect medium = {240, 130, 150, 50 };
  buttons.push_back(medium);
  SDL_Rect hard = {450, 130, 150, 50};
  buttons.push_back(hard);

  bool running = true;
  while (running) {

    while (SDL_PollEvent(&event)) {
      int x, y;
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        }
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&x, &y);
        switch (which_button(x, y, buttons)) {
        case 0: {
          cout << "easy" << endl;
          SDL_DestroyWindow(swin.window);
          Cube mycube;
          mycube.random_shuffle(5);
          break;
        }
        case 1: {
          cout << "medium" << endl;
          Cube mycube;
          mycube.random_shuffle(10);
          break;
        }
        case 2: {
          cout << "hard" << endl;
          Cube mycube;
          mycube.random_shuffle(20);
          break;
        }
        }
        break;
      }
    }

    swin.render();
  }

  return 0;
}  
