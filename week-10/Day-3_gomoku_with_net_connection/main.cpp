#include "game.h"
#include "communication.h"
#include <cstdlib>

int main(int argc, char* argv[]) {
  srand(time(NULL));
  Game game;
  GUserInterface gui;
  Communication comm(gui, game, "127.0.0.1");
  comm.run();
  return 0;
}



