#pragma once

#include <stdint.h>

int find_good_cells( const int32_t board[16][30], int32_t row [480], int32_t col[480] );

void change_board(int32_t a, int32_t b, const int32_t board[16][30], int32_t real_board[16][30]);

int32_t calculate(int32_t a, int32_t b, int32_t real_board[16][30], int32_t count[16][30], int32_t flag[16][30]);
