#include "gui.h"

GUserInterface::GUserInterface(Game& game) {
  this->game = &game;
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(window_title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    screen_width, screen_height, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  player1_pic = "pics/player1_32px.bmp";
  player2_pic = "pics/player2_32px.bmp";
  board_pic = "pics/board_32px.bmp";
  game_over_pic = "pics/gameover2.bmp";
  winner1_pic = "pics/player1_2.bmp";
  winner2_pic = "pics/player2_2.bmp";
  game_over = false;
  quit = false;
}

GUserInterface::~GUserInterface() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void GUserInterface::init() {
  init_right_viewport();
  SDL_RenderSetViewport( renderer, &rightViewport );
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  //SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
  init_left_viewport();
  SDL_RenderSetViewport( renderer, &leftViewport );
  load_file(player1_pic);
  load_file(player2_pic);
  load_file(board_pic);
  load_file(winner1_pic);
  load_file(winner2_pic);
  load_file(game_over_pic);
  draw_right_vp();
  draw_board(game->gameboard);
}

void GUserInterface::draw_right_vp() {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  TextRenderer my_text(renderer);
  std::string text = "Player";
  my_text.load_text(text);
  std::string player_pic = game->get_current_player().number == 1? winner1_pic: winner2_pic;
  tile_width = 60;
  tile_height = 60;
  SDL_RenderSetViewport( renderer, &rightViewport );
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  my_text.render_text(40, 40);
  draw_sprite(player_pic, 70, 110);
  SDL_RenderSetViewport( renderer, &leftViewport );
  tile_width = _tile_width;
  tile_height = _tile_height;
}

void GUserInterface::init_left_viewport() {
  leftViewport.x = 0;
  leftViewport.y = 0;
  leftViewport.w = left_vp_width;
  leftViewport.h = screen_height;
}

void GUserInterface::init_right_viewport() {
  rightViewport.x = left_vp_width;
  rightViewport.y = 0;
  rightViewport.w = right_vp_width;
  rightViewport.h = screen_height;
}

void GUserInterface::render() {
  SDL_RenderPresent(renderer);
}

void GUserInterface::load_file(std::string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
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

void GUserInterface::on_mouse_click(unsigned int x, unsigned int y) {
  if (game_over) {
    if (is_new_game_pushed(x, y)) {
      game_over = false;
      draw_right_vp();
      draw_board(game->gameboard);
    } else if (is_quit_pushed(x, y)) {
      quit = true;
    }
    return;
  }
  x /= tile_width;
  y /= tile_height;
  if(!game->next_turn(coordinate(x,y))) {
    run_game_over_routine();
  } else {
    draw_right_vp();
    draw_board(game->gameboard);
  }
}

bool GUserInterface::is_new_game_pushed(unsigned int x, unsigned int y) {
  if (x < game_over_win.pos_x + game_over_win.new_game_button.x + game_over_win.new_game_button.width &&
      x > game_over_win.pos_x + game_over_win.new_game_button.x &&
      y < game_over_win.pos_y + game_over_win.new_game_button.y + game_over_win.new_game_button.height &&
      y > game_over_win.pos_y + game_over_win.new_game_button.y) {
    return true;
  }
  return false;
}

bool GUserInterface::is_quit_pushed(unsigned int x, unsigned int y) {
  if (x < game_over_win.pos_x + game_over_win.quit_button.x + game_over_win.quit_button.width &&
      x > game_over_win.pos_x + game_over_win.quit_button.x &&
      y < game_over_win.pos_y + game_over_win.quit_button.y + game_over_win.quit_button.height &&
      y > game_over_win.pos_y + game_over_win.quit_button.y) {
    return true;
  }
  return false;
}

void GUserInterface::run_game_over_routine() {
  game_over = true;
  draw_right_vp();
  draw_board(game->gameboard);
  draw_game_over_texture(); ///
  game->reset();

}

void GUserInterface::draw_game_over_texture() {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  tile_width = game_over_win.width;
  tile_height = game_over_win.height;
  game_over_win.pos_x = left_vp_width/2-game_over_win.width/2;
  game_over_win.pos_y = screen_height/2-game_over_win.height/2;
  draw_sprite(game_over_pic, game_over_win.pos_x, game_over_win.pos_y);
  TextRenderer my_text(renderer);
  std::string winner_pic = game->get_current_player().number == 1? winner1_pic: winner2_pic;
  std::string text = "wins.";
  my_text.load_text(text);
  my_text.render_text(((int)game_over_win.pos_x + 140), (int)game_over_win.pos_y + 40);
  tile_width = 60;
  tile_height = 60;
  draw_sprite(winner_pic, game_over_win.pos_x + 60, game_over_win.pos_y + 20);
  tile_width = _tile_width;
  tile_height = _tile_height;
}

void GUserInterface::draw_board(board& gameboard) {
  for (uint i = 0; i < gameboard.size(); i++) {
    uint x = i * tile_width;
    for (uint j = 0; j < gameboard[i].size(); j++) {
      uint y = j * tile_height;
      if (gameboard[i][j] == 1) {
        draw_sprite(player1_pic, x, y);
      } else if (gameboard[i][j] == 2) {
        draw_sprite(player2_pic, x, y);
      } else {
        draw_sprite(board_pic, x, y);
      }
    }
  }

}

void GUserInterface::run() {
  init();
  SDL_Event event;
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
    case SDL_MOUSEBUTTONUP:
      int x, y;
      SDL_GetMouseState( &x, &y );
      on_mouse_click(x, y);
    }
    render();
  }
}
