#ifndef SDL_ENVIRONMENT_H_
#define SDL_ENVIRONMENT_H_
#include <SDL.h>
#include "Draw.h"

class SDL_environment {
  private:
    bool keys[5];
    Draw drawer;
  public:
    SDL_environment(const char* window_title = "Main",
                        unsigned int screen_width = 598,
                        unsigned int screen_height = 598);
    ~SDL_environment();
    SDL_Renderer* renderer;
    SDL_Window* window;
    void init(color background, color draw_color);
    void render();
    void reset_keys();
    void on_key_down(unsigned int key_code);
    bool was_key_pressed(unsigned int key_code);
    void MoveTo(int x, int y);
    void DrawTo(int x, int y);
};

#endif /* SDL_ENVIRONMENT_H_ */
