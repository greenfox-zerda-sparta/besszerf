#ifndef FRACTAL_DRAWER_H_
#define FRACTAL_DRAWER_H_
#include <utility>
#include "SDL_environment.h"

using namespace std;

struct square {
    pair<int, int> position;
    int offset;
};

class fractal_drawer {
  public:
    fractal_drawer();
    ~fractal_drawer();
    void run_environment();
  private:
    void draw(square& _square);
    void draw_fractal(int x, square& _square = my_square);
    SDL_environment* environment;
    square make_first_square(square& _square);
    square make_second_square(square& _square);
    square make_third_square(square& _square);
    square make_fourth_square(square& _square);
    static square my_square;
    color background;
    color draw_color;
};

#endif /* FRACTAL_DRAWER_H_ */
