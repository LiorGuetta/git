#include "../inc/sudoku.h"

int main() {
  int board[9][9];
  srand(time(0));
  for(int i=0; i<9; i++) 
      for(int j=0; j<9; j++) 
          board[i][j] = 0;

  fill_diagonal_boxes(board);
  fill_remaining(board);

  int holes = 58; 
  remove_digits(board, holes);
  printf("\nbefore\n\n");
  print_grid(board);
  printf("\nafter\n\n");
  solve_grid(board,0,0);
  print_grid(board);
  printf("\n");
  return 0;
}