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
  screen_drawer.draw_board(game->gameboard);
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
      screen_drawer.draw_board(game->gameboard);
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
    screen_drawer.draw_board(game->gameboard);
  }
}
