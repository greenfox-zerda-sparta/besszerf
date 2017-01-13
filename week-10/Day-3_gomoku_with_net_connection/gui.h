#ifndef GUI_H_
#define GUI_H_
#include <SDL.h>
#include <SDL_ttf.h>
#include "ui.h"
#include "textrenderer.h"

struct button1 {
    std::string value = "New game";
    unsigned int x = 26;
    unsigned int y = 105;
    unsigned int width = 100;
    unsigned int height = 25;
};

struct button2 {
    std::string value = "Quit";
    unsigned int x = 176;
    unsigned int y = 105;
    unsigned int width = 100;
    unsigned int height = 25;
};
struct comm_window {
    std::string value = "Game over!";
    unsigned int width = 300;
    unsigned int height = 150;
    unsigned int pos_x;
    unsigned int pos_y;
    button1 new_game_button;
    button2 quit_button;
};

class GUserInterface : public UserInterface {
  public:
    GUserInterface();
    ~GUserInterface();
    void init(data_share&);
    void run();
    void draw_board(board&);
    void draw_right_vp();
    void run_game_over_routine();
    void draw_connecting_window();
    void draw_player_sprite();
    void remove_mouse_events();
    comm_window panel;
  private:
    SDL_Event event;
    std::map<std::string, SDL_Texture*> sprites;
    SDL_Renderer* renderer;
    SDL_Window* window;
    bool quit;
    void load_file(std::string name);
    void draw_sprite(std::string name, int x, int y);
    void render();
    void on_mouse_click(unsigned int x, unsigned int y);
    std::string player1_pic;
    std::string player2_pic;
    std::string board_pic;
    std::string game_over_pic;
    std::string pure_window_pic;
    std::string winner1_pic;
    std::string winner2_pic;
    bool game_over;
    void put_panel_out(std::string pic);
    void draw_game_over_window();
    SDL_Rect leftViewport;
    SDL_Rect rightViewport;
    void init_left_viewport();
    void init_right_viewport();
    data_share* shared_data;
};
#endif /* GUI_H_ */
