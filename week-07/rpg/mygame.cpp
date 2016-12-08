#include "mygame.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

void MyGame::init(GameContext& context) {
  context.load_file("pics/floor.bmp");
  context.load_file("pics/wall.bmp");
  context.load_file("pics/hero-down.bmp");
  context.load_file("pics/hero-up.bmp");
  context.load_file("pics/hero-left.bmp");
  context.load_file("pics/hero-right.bmp");
  context.load_file("pics/skeleton.bmp");
  context.load_file("pics/boss.bmp");
}

void MyGame::render(GameContext& context) {
  for (uint i = 0; i < myBoard.size(); i++) {
    uint x = i * tile_width;
    for (uint j = 0; j < myBoard[i].size(); j++) {
      uint y = j * tile_height;
      context.draw_sprite((myBoard[i][j]?"pics/floor.bmp":"pics/wall.bmp"), x, y);
    }
  }
  for (int i = 0; i < bad_boys_count; i++) {
    if (i == 0) {
      context.draw_sprite("pics/boss.bmp", bad_boys_positions[i].get_x(), bad_boys_positions[i].get_y());
    } else {
      context.draw_sprite("pics/skeleton.bmp", bad_boys_positions[i].get_x(), bad_boys_positions[i].get_y());
    }
  }
  context.draw_sprite(hero_pic, hero_position.get_x(), hero_position.get_y());
  hero_move(context);
  context.render();
}

MyGame::MyGame() {
  myBoard = board(board_rows, row(board_cols, 0));
  drawLevel(0, 0, 0);
  hero_pic = "pics/hero-down.bmp";
  set_hero_initial_position();
  bad_boys_count = 4;
  bad_boys_positions = vector<Point2d>(bad_boys_count);
  for (int i = 0; i < bad_boys_count; i++) {
    bad_boys_positions[i] = set_badboy_position();
  }
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
      if (++x > board_cols - 1) {
        x = board_cols - 1;
        dir = rand() % 4;
      }
      if (!myBoard[x][y]) {
        ++covered;
        myBoard[x][y] = 1;
      }
    } else if (dir == 1) { //down
      if (++y > board_rows - 1) {
        y = board_rows - 1;
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
  return;
}

void MyGame::set_hero_initial_position() {
  for (uint i = 0; i < myBoard.size(); i++) {
    for (uint j = 0; j < myBoard[i].size(); j++) {
      if (myBoard[i][j]) {
        hero_position.set_x(i * tile_width);
        hero_position.set_y(j * tile_height);
        return;
      }
    }
  }
}

Point2d MyGame::set_badboy_position() {
  Point2d position;
  do {
    position.set_x((rand() % board_cols) * tile_width);
    position.set_y((rand() % board_rows) * tile_height);
  } while (!is_a_good_position(position));
  return position;
}

bool MyGame::is_a_good_position(Point2d position) {
  int x = position.get_x()/tile_width;
  int y = position.get_y()/tile_width;
  if (!myBoard[x][y]) {
    return false;
  }
  for (int i = 0; i < bad_boys_count; i++) {
    if (bad_boys_positions[i] == position) {
      return false;
    }
  }
  if (hero_position == position) {
    return false;
  }
  return true;
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

void MyGame::hero_move(GameContext& context) {
  int x = hero_position.get_x()/tile_width;
  int y = hero_position.get_y()/tile_height;
  if (context.was_key_pressed(ARROW_DOWN)) {
    if (y < board_rows - 1 && myBoard[x][y + 1]) {
      hero_position.set_y(hero_position.get_y() + tile_height);
      hero_pic = "pics/hero-down.bmp";
    }
  }
  if (context.was_key_pressed(ARROW_UP)) {
    if (y > 0 && myBoard[x][y - 1]) {
      hero_position.set_y(hero_position.get_y() - tile_height);
      hero_pic = "pics/hero-up.bmp";
    }
  }
  if (context.was_key_pressed(ARROW_LEFT)) {
    if (x > 0 && myBoard[x - 1][y]) {
      hero_position.set_x(hero_position.get_x() - tile_width);
      hero_pic = "pics/hero-left.bmp";
    }
  }
  if (context.was_key_pressed(ARROW_RIGHT)) {
    if (x < board_cols - 1 && myBoard[x + 1][y]) {
      hero_position.set_x(hero_position.get_x() + tile_width);
      hero_pic = "pics/hero-right.bmp";
    }
  }
}
