#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "winnerlinechecker.h"
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
    void reset();
    Player get_current_player();
    board gameboard;
    void set_next_player();
  private:
    Player player1;
    Player player2;
    Player* current_player;
    WinnerLineChecker winner_checker;
    bool is_not_engaged(coordinate&);
    void set_board(coordinate&);
    bool has_current_player_won(coordinate&);

};



#endif /* GAME_H_ */
