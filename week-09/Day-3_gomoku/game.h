#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "winnerlinechecker.h"
#include "screendrawer.h"
#include <iostream>

using namespace std;

typedef vector<char> row;
typedef vector<row> board;
typedef std::pair<char, char> coordinate;

class Game {
  public:
    Game();
    ~Game();
    bool next_turn(coordinate);
    void draw_board();
    void reset();
    Player get_current_player();
  private:
    board gameboard;
    Player player1;
    Player player2;
    Player* current_player;
    WinnerLineChecker winner_checker;
    ScreenDrawer screen_drawer;
    void set_next_player();
    bool is_not_engaged(coordinate&);
    void set_board(coordinate&);
    bool has_current_player_won(coordinate&);

};



#endif /* GAME_H_ */
