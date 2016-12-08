#ifndef UTIL_H_
#define UTIL_H_
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

typedef std::vector<bool> row;
typedef std::vector<row> board;
typedef unsigned int uint;

extern int board_rows;
extern int board_cols;
extern int screen_width;
extern int screen_height;
extern int tile_width;
extern int tile_height;
extern int num_of_sceletons;

std::string to_string(int integer);

extern const int STEPS[15];
extern const int MAX_FLOORTILE_COUNT;

void print_board(board myBoard);

#endif /* UTIL_H_ */
