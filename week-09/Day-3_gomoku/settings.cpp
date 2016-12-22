#include "settings.h"

int board_row_size = 19;
int board_col_size = 19;
char board_sign = 0;
char p1_sign = 1;
char p2_sign = 2;
char tile_width = 24;
char tile_height = 24;
const char* window_title = "Gomoku by Me";
unsigned int screen_width = board_row_size * tile_width;
unsigned int screen_height = board_col_size * board_col_size;

