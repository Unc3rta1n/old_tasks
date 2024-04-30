#pragma once
#include <stdbool.h>
void clearscreen();
void clearboard();
bool has_wonQ(char player);
void print_board();
int get_move();
char play_and_get_winner();
char board[9];
