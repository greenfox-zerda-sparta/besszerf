#include "mygame.h"
#include <iostream>

typedef unsigned int uint;

void MyGame::init(GameContext& context) {
  context.load_file("pics/floor.bmp");
  context.load_file("pics/wall.bmp");
}

void MyGame::render(GameContext& context) {
  for (uint i = 0; i < myBoard.size(); i++) {
    uint x = i * tile_height;
    for (uint j = 0; j < myBoard[i].size(); j++) {
      uint y = j * tile_width;
      context.draw_sprite((myBoard[i][j]?"pics/floor.bmp":"pics/wall.bmp"), y, x);
    }
  }
  context.render();
}

MyGame::MyGame() {
  myBoard = board(board_rows, row(board_cols, 0));
  drawLevel(0, 0, 0);
}

MyGame::~MyGame() {}

void MyGame::drawLevel(int x, int y, int covered){
  if (!myBoard[x][y]) {
    myBoard[x][y] = 1;
    ++covered;
  }
  if (covered >= COVERABLE){
    return;
  }
  int stp = rand() % 15;
  int dir = rand() % 4;
  for (int i = 1; i <= STEPS[stp]; ++i){
    if(dir == 0){ //right
      if (++x > board_rows - 1) {
        x = board_rows - 1;
        dir = rand() % 4;
      }
      if (!myBoard[x][y]) {
        ++covered;
        myBoard[x][y] = 1;
      }
    } else if (dir == 1) { //down
      if (++y > board_cols - 1) {
        y = board_cols - 1;
        dir = rand() % 4;
      }
      if (!myBoard[x][y]) {
        ++covered;
        myBoard[x][y] = 1;
      }
    } else if (dir == 2) { // left
      if (--x < 0) {
        x = 0;
        dir = rand() % 4;
      }
      if (!myBoard[x][y]) {
        ++covered;
        myBoard[x][y] = 1;
      }
    } else { // up
      if (--y < 0) {
        y = 0;
        dir = rand() % 4;
      }
      if(!myBoard[x][y]){
        ++covered;
        myBoard[x][y] = 1;
      }
    }
    if (covered == COVERABLE){
      return;
    }
  }
  drawLevel(x, y, covered);
  return; //for safety, shoud never reach this line anyways...
}

void MyGame::print_board() {
  for (uint i = 0; i < myBoard.size(); i++) {
    for (uint j = 0; j < myBoard[i].size(); j++) {
      std::cout << myBoard[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

