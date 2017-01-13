#include "gui.h"

GUserInterface::GUserInterface() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(window_title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    screen_width, screen_height, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  player1_pic = "pics/player1_32.bmp";
  pure_window_pic = "pics/panel.bmp";
  player2_pic = "pics/player2_32.bmp";
  board_pic = "pics/board_32.bmp";
  game_over_pic = "pics/gameover2.bmp";
  winner1_pic = "pics/player1_2.bmp";
  winner2_pic = "pics/player2_2.bmp";
  game_over = false;
  quit = false;
  shared_data = NULL;
}

GUserInterface::~GUserInterface() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void GUserInterface::init(data_share& data_pack) {
  this->shared_data = &data_pack;
  init_right_viewport();
  SDL_RenderSetViewport( renderer, &rightViewport );
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  init_left_viewport();
  SDL_RenderSetViewport( renderer, &leftViewport );
  load_file(player1_pic);
  load_file(player2_pic);
  load_file(board_pic);
  load_file(winner1_pic);
  load_file(winner2_pic);
  load_file(game_over_pic);
  load_file(pure_window_pic);
  draw_right_vp();
  draw_board((this->shared_data->game)->gameboard);
  draw_connecting_window();
}

void GUserInterface::draw_player_sprite() {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  tile_width = 60;
  tile_height = 60;
  std::string player_pic;
  SDL_RenderSetViewport( renderer, &rightViewport );
  if(shared_data->player == 1) {
    player_pic = winner1_pic;
    draw_sprite(player_pic, 70, 250);
  }
  if(shared_data->player == 2) {
    player_pic = winner2_pic;
    draw_sprite(player_pic, 70, 250);
  }
  tile_width = _tile_width;
  tile_height = _tile_height;
}

void GUserInterface::draw_right_vp() {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  TextRenderer my_text(renderer);
  std::string text = "Current:";
  my_text.load_text(text);
  std::string player_pic = shared_data->game->get_current_player().number == 1? winner1_pic: winner2_pic;
  tile_width = 60;
  tile_height = 60;
  SDL_RenderSetViewport( renderer, &rightViewport );
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  my_text.render_text(40, 40);
  draw_sprite(player_pic, 70, 90);

  text = "You:";
  my_text.load_text(text);
  my_text.render_text(40, 200);
  draw_player_sprite();

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
  shared_data->x = x;
  shared_data->y = y;
}

void GUserInterface::run_game_over_routine() {
  shared_data->game_over = true;
  draw_right_vp();
  draw_board(shared_data->game->gameboard);
  draw_game_over_window(); ///
  shared_data->game->reset();

}

void GUserInterface::put_panel_out(std::string pic) {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  tile_width = panel.width;
  tile_height = panel.height;
  panel.pos_x = left_vp_width/2-panel.width/2;
  panel.pos_y = screen_height/2-panel.height/2;
  draw_sprite(pic, panel.pos_x, panel.pos_y);
  tile_width = _tile_width;
  tile_height = _tile_height;
}

void GUserInterface::draw_game_over_window() {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  put_panel_out(game_over_pic);
  TextRenderer my_text(renderer);
  std::string winner_pic = shared_data->game->get_current_player().number == 1? winner1_pic: winner2_pic;
  std::string text = "wins.";
  my_text.load_text(text);
  my_text.render_text(((int)panel.pos_x + 140), (int)panel.pos_y + 40);
  tile_width = 60;
  tile_height = 60;
  draw_sprite(winner_pic, panel.pos_x + 60, panel.pos_y + 20);
  tile_width = _tile_width;
  tile_height = _tile_height;
}

void GUserInterface::draw_connecting_window() {
  char _tile_width = tile_width;
  char _tile_height = tile_height;
  put_panel_out(pure_window_pic);
  TextRenderer my_text(renderer);
  my_text.set_font_size(15);
  std::string text = "Connecting to remote player...";
  my_text.load_text(text);
  my_text.render_text(((int)panel.pos_x + 12), (int)panel.pos_y + 60);
  my_text.reset_font_size();
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
  render();
  SDL_WaitEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    shared_data->quit = true;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
      shared_data->quit = true;
      break;
    }
    break;
  case SDL_MOUSEBUTTONDOWN:
    on_mouse_click(event.button.x, event.button.y);
  }
}

void GUserInterface::remove_mouse_events() {
  SDL_PumpEvents();
  SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
}
