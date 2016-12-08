#include "mygame.h"
using namespace std;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  MyGame game;
  GameEngine engine(&game, screen_width, screen_height);
  engine.run();
  return 0;
}
