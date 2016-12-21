#include "userinterface.h"

UserInterface::UserInterface(Game& game) {
  this->game = &game;
}

UserInterface::~UserInterface() {}

void UserInterface::run() {
  cout << endl;
  int a;
  int b;
  char x;
  char y;
  coordinate act_coord;
  cout << "Simple Gomoku Game" << endl << endl;
  game->draw_board();
  while (true) {
    cout << "Player " << game->get_current_player().player << endl;
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
      game->draw_board();
      char answer;
      cout << "Player " << game->get_current_player().player << " wins." << endl;
      cout << "One more game (y/n)? ";
      cin >> answer;
      if (answer != 'y') {
        cout << "Bye!" << endl;
        return;
      } else {
        game->reset();
      }
    }
    game->draw_board();
  }
}
