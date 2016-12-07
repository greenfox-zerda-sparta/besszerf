#include "mygame.h"
#include <iostream>

typedef unsigned int uint;

void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
}

void MyGame::render(GameContext& context) {
  for (uint i = 0; i < myBoard.size(); i++) {
    uint x = i * tile_height;
    for (uint j = 0; j < myBoard[i].size(); j++) {
      uint y = j * tile_width;
      context.draw_sprite("floor.bmp", x, y);
    }
  }
  context.render();
}

MyGame::MyGame() {
  myBoard = board(10, row(10, 0));
}

MyGame::~MyGame() {}

