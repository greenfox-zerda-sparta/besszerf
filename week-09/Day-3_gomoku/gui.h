#ifndef GUI_H_
#define GUI_H_
#include <SDL.h>
#include "ui.h"

class GUserInterface : public UserInterface {
  public:
    void run();
    GUserInterface(Game& game);
    ~GUserInterface();
  private:
    std::map<std::string, SDL_Texture*> sprites;
    SDL_Renderer* renderer;
    SDL_Window* window;
    void init();
    void load_file(std::string name);
    void draw_sprite(std::string name, int x, int y);
    void render();
    void draw_board(board&);
    void on_mouse_click(char x, char y);
    std::string pic1;
    std::string pic2;
    std::string pic3;
};
#endif /* GUI_H_ */
