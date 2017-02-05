#include "Opengl.hpp"

Opengl::Opengl() {
}

Opengl::~Opengl() {
}

void Opengl::opengl_init(int width, int height) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)width / height, 1, 1000);
  glEnable(GL_DEPTH_TEST);
}

void Opengl::opengl_sreenbuilder() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Opengl::opengl_display(SDL_Window* screen) {
  glFlush();
  SDL_GL_SwapWindow(screen);
}