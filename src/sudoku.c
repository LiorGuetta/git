#include "../inc/sudoku.h"

int solve_grid(int grid[9][9],int row,int col)
{
    if (row == 8 && col == 9)
    {
        return 1;  
    } 
    if (col == 9) 
    { 
        row++; col = 0; 
    }
    if (grid[row][col] != 0)
    {
        return (solve_grid(grid, row, col + 1));
    }
    for (int num = 1; num <= 9; num++) 
    {
        if (is_safe(grid,row,col,num)) 
        {
            grid[row][col] = num;
            if (solve_grid(grid,row,col + 1))
            {
                return 1; 
            } 
            grid[row][col] = 0;
        }
    }
    return 0;
}

void remove_digits(int grid[9][9], int count) {
    while (count != 0) {
        int cell_id = rand() % 81;
        int i = cell_id / 9;
        int j = cell_id % 9;
        if (grid[i][j] != 0) {
            count--;
            grid[i][j] = 0;
        }
    }
}

int is_safe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num || grid[x][col] == num) return 0;
    int sRow = row - row % 3, sCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + sRow][j + sCol] == num) return 0;
    return 1;
}

int fill_remaining(int grid[9][9]) {
    int row, col, empty = 0;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) { empty = 1; break; }
        }
        if (empty) break;
    }
    if (!empty) return 1;
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (fill_remaining(grid)) return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

void fill_diagonal_boxes(int grid[9][9]) {
    for (int i = 0; i < 9; i += 3) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                int num;
                do { num = (rand() % 9) + 1; } while (!is_safe(grid, i + row, i + col, num));
                grid[i + row][i + col] = num;
            }
        }
    }
}

void print_grid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
            if ((j + 1) % 3 == 0 && j < 8) printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < 8) printf("------+-------+------\n");
    }
}