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
struct game_over_window {
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
    void run();
    GUserInterface(Game& game);
    ~GUserInterface();
  private:
    std::map<std::string, SDL_Texture*> sprites;
    SDL_Renderer* renderer;
    SDL_Window* window;
    bool quit;
    void init();
    void load_file(std::string name);
    void draw_sprite(std::string name, int x, int y);
    void render();
    void draw_board(board&);
    void on_mouse_click(unsigned int x, unsigned int y);
    std::string player1_pic;
    std::string player2_pic;
    std::string board_pic;
    std::string game_over_pic;
    std::string winner1_pic;
    std::string winner2_pic;
    bool game_over;
    void run_game_over_routine();
    void draw_game_over_texture();
    bool is_quit_pushed(unsigned int x, unsigned int y);
    bool is_new_game_pushed(unsigned int x, unsigned int y);
    game_over_window game_over_win;
    SDL_Rect leftViewport;
    SDL_Rect rightViewport;
    void init_left_viewport();
    void init_right_viewport();
    void draw_right_vp();

};
#endif /* GUI_H_ */
