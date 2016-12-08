#include "mygame.h"

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
  gameBoard.draw(context);
  for (int i = faces.size()-1; i > -1; i--) {
    faces[i]->draw(context);
 }
  faces[0]->move(context);
  context.render();
}

MyGame::MyGame() {
  gameBoard = RandomBoard();
  faces.push_back(new Hero(gameBoard.get_board()));
  std::vector<Point2d> positions;
  positions.push_back(faces[0]->get_position());
  faces.push_back(new Boss(gameBoard.get_board(), positions));
  positions.push_back(faces[1]->get_position());
  for (int i = 0; i < num_of_sceletons; i++) {
    faces.push_back(new Skeleton(gameBoard.get_board(), positions));
    positions.push_back(faces[i + 2]->get_position());
  }
}

MyGame::~MyGame() {
  for (uint i = 0; i < faces.size(); i++) {
    delete faces[i];
  }
}

std::vector<Killers*> MyGame::get_faces() {
  return faces;
}

