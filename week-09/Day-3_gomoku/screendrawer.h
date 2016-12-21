#ifndef SCREENDRAWER_H_
#define SCREENDRAWER_H_
#include "settings.h"
#include <vector>
#include <iostream>

typedef std::vector<char> row;
typedef std::vector<row> board;
typedef std::pair<char, char> coordinate;



class ScreenDrawer {
  public:
    void draw_board(board& gameboard);
};



#endif /* SCREENDRAWER_H_ */
