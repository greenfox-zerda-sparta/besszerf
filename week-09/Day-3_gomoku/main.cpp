#include "game.h"
#include "gui.h"

int main(int argc, char* argv[]) {
  Game game;
  GUserInterface gui(game);
  gui.run();
  return 0;
}



