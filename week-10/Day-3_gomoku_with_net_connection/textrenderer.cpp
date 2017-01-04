#include "textrenderer.h"


TextRenderer::TextRenderer(SDL_Renderer* renderer) {
  this->renderer = renderer;
  text_texture = 0;
  text_width = 0;
  text_height = 0;
  TTF_Init();
  gFont = TTF_OpenFont( "/usr/share/fonts/truetype/liberation/LiberationMono-Bold.ttf", 32 );
}

void TextRenderer::free_text_surface() {
  if( text_texture != NULL )
  {
    SDL_DestroyTexture( text_texture );
    text_texture = NULL;
    text_width = 0;
    text_height = 0;
  }
}

void TextRenderer::loadFromRenderedText( std::string textureText, SDL_Color textColor ) {
  free_text_surface();
  SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
  text_texture = SDL_CreateTextureFromSurface(renderer, textSurface );
  text_width = textSurface->w;
  text_height = textSurface->h;
  SDL_FreeSurface( textSurface );
}

void TextRenderer::load_text(std::string text) {
  SDL_Color textColor = { 50, 50, 50 };
  loadFromRenderedText( text, textColor );
}

void TextRenderer::render_text(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
  SDL_Rect renderQuad = { x, y, text_width, text_height };
  if( clip != NULL )
  {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }
  SDL_RenderCopyEx(renderer, text_texture, clip, &renderQuad, angle, center, flip );
}



