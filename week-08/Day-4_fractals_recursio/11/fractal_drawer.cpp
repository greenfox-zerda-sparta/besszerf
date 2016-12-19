#include "fractal_drawer.h"

square fractal_drawer::my_square;

fractal_drawer::fractal_drawer() {
  char title[] = "Square Fractal";
environment = new SDL_environment(title, 598, 598);
  background = {255, 255, 170};
  draw_color = {0, 0, 0};
  my_square.offset = 594;
  my_square.position = make_pair(1,1);
}

fractal_drawer::~fractal_drawer() {
  delete environment;
}

void fractal_drawer::draw(square& _square) {
  environment->MoveTo(_square.position.first, _square.position.second);
  environment->DrawTo(_square.position.first, _square.position.second + _square.offset);
  environment->DrawTo(_square.position.first + _square.offset, _square.position.second + _square.offset);
  environment->DrawTo(_square.position.first + _square.offset, _square.position.second);
  environment->DrawTo(_square.position.first, _square.position.second);

}

void fractal_drawer::draw_fractal(int x, square& _square) {
  draw(_square);
  if (x < 2) {
    return;
  }
  square square1 = make_first_square(_square);
  square square2 = make_second_square(_square);
  square square3 = make_third_square(_square);
  square square4 = make_fourth_square(_square);
  --x;
  draw_fractal(x, square1);
  draw_fractal(x, square2);
  draw_fractal(x, square3);
  draw_fractal(x, square4);

}

square fractal_drawer::make_first_square (square& _square) {
  square _square_;
  _square_.offset = _square.offset / 3;
  _square_.position.first = _square.position.first + _square_.offset;
  _square_.position.second = _square.position.second;
  return _square_;
}

square fractal_drawer::make_second_square (square& _square) {
  square _square_;
  _square_.offset = _square.offset / 3;
  _square_.position.first = _square.position.first + 2 * _square_.offset;
  _square_.position.second = _square.position.second + _square_.offset;
  return _square_;
}

square fractal_drawer::make_third_square (square& _square) {
  square _square_;
  _square_.offset = _square.offset / 3;
  _square_.position.first = _square.position.first + _square_.offset;
  _square_.position.second = _square.position.second + 2 * _square_.offset;
  return _square_;
}

square fractal_drawer::make_fourth_square (square& _square) {
  square _square_;
  _square_.offset = _square.offset / 3;
  _square_.position.first = _square.position.first;
  _square_.position.second = _square.position.second + _square_.offset;
  return _square_;
}

void fractal_drawer::run_environment() {
  environment->init(background, draw_color);
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
/*********************************************/
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        quit = true;
        break;
      case SDLK_DOWN:
        environment->init(background, draw_color);
        draw_fractal(6); //////////////////////////////////////
        break;
      }
    }
  /*********************************************/
    environment->render();
  }
}
