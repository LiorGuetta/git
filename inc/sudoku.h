#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNASSIGNED (0)

int is_safe(int grid[9][9], int row, int col, int num);
int fill_remaining(int grid[9][9]);
void fill_diagonal_boxes(int grid[9][9]);
void remove_digits(int grid[9][9], int count);
void print_grid(int grid[9][9]);
int solve_grid(int grid[9][9], int row, int col);

#endif