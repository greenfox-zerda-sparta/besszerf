#ifndef UTIL_H_
#define UTIL_H_
#include <string>
#include <sstream>

extern int board_rows;
extern int board_cols;
extern int screen_width;
extern int screen_height;
extern int tile_width;
extern int tile_height;

std::string to_string(int integer);

extern const int STEPS[15];
#endif /* UTIL_H_ */
