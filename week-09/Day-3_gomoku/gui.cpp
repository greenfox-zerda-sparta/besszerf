#include "gui.h"

GUserInterface::GUserInterface(Game& game) {
  this->game = &game;
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(window_title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    screen_width, screen_height, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  pic1 = "pics/player1.bmp";
  pic2 = "pics/player2.bmp";
  pic3 = "pics/board.bmp";
}

GUserInterface::~GUserInterface() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void GUserInterface::init() {
  load_file(pic1);
  load_file(pic2);
  load_file(pic3);
  draw_board(game->gameboard);
}

void GUserInterface::render() {
  SDL_RenderPresent(renderer);
}

void GUserInterface::load_file(std::string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
  SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(window)), 0xFF, 0, 0xFF));
  sprites[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}
void GUserInterface::draw_sprite(std::string name, int x, int y) {
  SDL_Rect temp;
  temp.x = x;
  temp.y = y;
  temp.w = tile_width;
  temp.h = tile_height;
  SDL_RenderCopy(renderer, sprites[name], NULL, &temp);
}

void GUserInterface::on_mouse_click(char x, char y) {
  if(!game->next_turn(coordinate(x,y))) {
    draw_board(game->gameboard);
    game->reset();
  }
    draw_board(game->gameboard);

}

void GUserInterface::draw_board(board& gameboard) {
  for (uint i = 0; i < gameboard.size(); i++) {
    uint x = i * tile_width;
    for (uint j = 0; j < gameboard[i].size(); j++) {
      uint y = j * tile_height;
      if (gameboard[i][j] == 1) {
        draw_sprite(pic1, x, y);
      } else if (gameboard[i][j] == 2) {
        draw_sprite(pic2, x, y);
      } else {
        draw_sprite(pic3, x, y);
      }
    }
  }

}

void GUserInterface::run() {
  init();
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        quit = true;
        break;
      }
      break;
  /*********************************************/
    case SDL_MOUSEBUTTONUP:
      int x, y;
      SDL_GetMouseState( &x, &y );
      x /= tile_width;
      y /= tile_height;
      on_mouse_click((char)x, (char)y);
    }
  /*********************************************/
    render();
  }
}
