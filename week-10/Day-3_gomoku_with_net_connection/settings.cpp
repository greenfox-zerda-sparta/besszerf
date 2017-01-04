#include "settings.h"

int board_row_size = 19;
int board_col_size = 19;
char board_sign = 0;
char p1_sign = 1;
char p2_sign = 2;
int tile_width = 32;
int tile_height = 32;
const char* window_title = "Gomoku by Me";
unsigned int left_vp_width = board_row_size * tile_width;
unsigned int right_vp_width = 200;
unsigned int screen_width = left_vp_width + right_vp_width;
unsigned int screen_height = board_col_size * tile_height;
