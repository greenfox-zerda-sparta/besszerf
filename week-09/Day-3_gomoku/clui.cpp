#include "clui.h"

CLUserInterface::CLUserInterface(Game& game) {
  this->game = &game;
}

void CLUserInterface::run() {
  cout << endl;
  int a;
  int b;
  char x;
  char y;
  coordinate act_coord;
  cout << "Simple Gomoku Game" << endl << endl;
  draw_board();
  while (true) {
    cout << "Player " << game->get_current_player().number << endl;
    cout << "Choosen coordinates (x y): ";
    cin >> a >> b;
    x = (char)a;
    y = (char)b;
    if (x > 19 || x < 1 || y > 19 || y < 1) {
      cout << "Bye!" << endl;
      return;
    }
    act_coord = {x-1, y-1};
    if(!game->next_turn(act_coord)) {
      draw_board();
      char answer;
      cout << "Player " << game->get_current_player().number << " wins." << endl;
      cout << "One more game (y/n)? ";
      cin >> answer;
      if (answer != 'y') {
        cout << "Bye!" << endl;
        return;
      } else {
        game->reset();
      }
    }
    draw_board();
  }
}

void CLUserInterface::draw_board() {
  for (unsigned int i = 0; i < game->gameboard.size(); ++i) {
    for (unsigned int j = 0; j < game->gameboard[i].size(); ++j) {
      std::cout << (int)game->gameboard[j][game->gameboard[i].size() -1 -i] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

