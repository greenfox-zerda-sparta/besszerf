#ifndef WINNERLINECHECKER_H_
#define WINNERLINECHECKER_H_
#include "settings.h"
#include <iostream>

typedef std::pair<char, char> dir_vector;
struct Player {
    int player;
    int sign;

};

typedef std::vector<char> row;
typedef std::vector<row> board;
typedef std::pair<char, char> coordinate;


class WinnerLineChecker {
  public:
    WinnerLineChecker();
    ~WinnerLineChecker();
    bool is_a_winner_line(board& gameboard, coordinate&, Player* current_player);
  private:
    Player* current_player;
    char winner_item_count;
    bool can_count_to_negative_direction;
    bool can_count_to_positive_direction;
    dir_vector negative_vector;
    dir_vector positive_vector;
    void reset();
    bool is_a_winner_line_horizontally(board& gameboard, coordinate&);
    bool is_a_winner_line_vertically(board& gameboard, coordinate&);
    bool is_a_winner_line_from_left_to_down(board& gameboard, coordinate&);
    bool is_a_winner_line_from_right_to_down(board& gameboard, coordinate&);
    bool run_winner_searching_cycle(board& gameboard, coordinate&);
    void count_to_negative_direction(board& gameboard, coordinate&);
    void count_to_positive_direction(board& gameboard, coordinate&);
    bool is_a_winner_sign_towards(board& gameboard, coordinate&);
    bool is_a_winner_sign_backwards(board& gameboard, coordinate&);
    void decrement_negative_coordinate_in_cycle(coordinate&);
    void increment_positive_coordinate_in_cycle(coordinate&);

};
#endif /* WINNERLINECHECKER_H_ */

