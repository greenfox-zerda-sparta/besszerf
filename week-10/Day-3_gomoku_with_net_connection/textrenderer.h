#ifndef TEXTRENDERER_H_
#define TEXTRENDERER_H_
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextRenderer {
  public:
    TextRenderer(SDL_Renderer*);
    void load_text(std::string text);
    void render_text(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void set_font_size(int);
    void reset_font_size();
  private:
    TTF_Font *gFont;
    int font_size;
    SDL_Texture* text_texture;
    SDL_Renderer* renderer;
    int text_width;
    int text_height;
    void loadFromRenderedText( std::string textureText, SDL_Color textColor );
    void free_text_surface();
};



#endif /* TEXTRENDERER_H_ */
