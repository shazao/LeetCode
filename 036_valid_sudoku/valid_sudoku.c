/* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. */

// Star: 7.5.

#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
  if (boardRowSize!=9 || boardColSize!=9)
    return false;

  unsigned char flag[9] = { 0 };

  int i = 0;
  int j = 0;
  for (i=0; i<boardRowSize; ++i) {
    for (j=0; j<boardColSize; ++j)
      flag[j] = 0;
    for (j=0; j<boardColSize; ++j) {
      char c = board[i][j];
      int idx = c - '0' - 1;
      if (c != '.') {
        if (flag[idx]==0) {
          flag[idx] = 1;
          continue;
        }
        if (flag[idx] == 1)
          return false;
      }
    }
  }

  for (i=0; i<boardRowSize; ++i) {
    for (j=0; j<boardRowSize; ++j)
      flag[j] = 0;
    for (j=0; j<boardColSize; ++j) {
      char c = board[j][i];
      int idx = c - '0' - 1;
      if (c != '.') {
        if (flag[idx]==0) {
          flag[idx] = 1;
          continue;
        }
        if (flag[idx] == 1)
          return false;
      }
    }
  }

  int k = 0;
  for (i=0; i<boardRowSize; i+=3) {
    for (j=0; j<boardColSize; j+=3) {
      for (k=0; k<9; ++k)
        flag[k] = 0;
      for (k=0; k<9; ++k) {
        char c = board[i+k/3][j+k%3];
        int idx = c - '0' - 1;
        if (c != '.') {
          if (flag[idx]==0) {
            flag[idx] = 1;
            continue;
          }
          if (flag[idx] == 1)
            return false;
        }
      }
    }
  }

  //char * brd = *board;
  //int i = 0;
  //int j = 0;
  //for (i=0; i<boardRowSize; ++i) {
  //  for (j=0; j<boardColSize; ++j)
  //    flag[j] = 0;
  //  for (j=0; j<boardColSize; ++j)
  //    if (brd[i*boardColSize+j] != '.') {
  //      if (flag[brd[i*boardColSize+j]-0x30]==0) {
  //        flag[brd[i*boardColSize+j]-0x30] = 1;
  //        continue;
  //      }
  //      if (flag[brd[i*boardColSize+j]-0x30] == 1)
  //        return false;
  //    }
  //}

  //for (i=0; i<boardRowSize; ++i) {
  //  for (j=0; j<boardRowSize; ++j)
  //    flag[j] = 0;
  //  for (j=0; j<boardColSize; ++j)
  //    if (brd[j*boardColSize+i] != '.') {
  //      if (flag[brd[j*boardColSize+i]-0x30]==0) {
  //        flag[brd[j*boardColSize+i]-0x30] = 1;
  //        continue;
  //      }
  //      if (flag[brd[j*boardColSize+i]-0x30] == 1)
  //        return false;
  //    }
  //}

  //int k = 0;
  //for (i=0; i<boardRowSize; i+=3) {
  //  for (j=0; j<boardColSize; j+=3) {
  //    for (k=0; k<9; ++k)
  //      flag[k] = 0;
  //    for (k=0; k<9; ++k)
  //      if (brd[(i+k/3)*boardColSize+j+k%3] != '.') {
  //        if (flag[brd[(i+k/3)*boardColSize+j+k%3]-0x30]==0) {
  //          flag[brd[(i+k/3)*boardColSize+j+k%3]-0x30] = 1;
  //          continue;
  //        }
  //        if (flag[brd[(i+k/3)*boardColSize+j+k%3]-0x30] == 1)
  //          return false;
  //      }
  //  }
  //}

  return true;
}

void main() {

  //char * board[] = { 
  //  "9.4....13",
  //  "..39.....",
  //  "...68.9..",
  //  "....3.6.1",
  //  "..2...7..",
  //  "5.1.2....",
  //  "..6.51...",
  //  ".....93..",
  //  "29....1.6"
  //};
  char * board[] = {
    "..5.....6",
    "....14...",
    ".........",
    ".....92..",
    "5....2...",
    ".......3.",
    "...54....",
    "3.....42.",
    "...27.6.."
  };

  bool result = isValidSudoku(board, 9, 9); // Note: Array is converted to pointer.

  if (result)
    printf("The Sudoku is valid.\n");
  else 
    printf("The Sudoku is invalid.\n");

}

//char board[9][9] = { 
//  '9', '.', '4', '.', '.', '.', '.', '1', '3',
//  '.', '.', '3', '9', '.', '.', '.', '.', '.',
//  '.', '.', '.', '6', '8', '.', '9', '.', '.',
//  '.', '.', '.', '.', '3', '.', '6', '.', '1',
//  '.', '.', '2', '.', '.', '.', '7', '.', '.',
//  '5', '.', '1', '.', '2', '.', '.', '.', '.',
//  '.', '.', '6', '.', '5', '1', '.', '.', '.',
//  '.', '.', '.', '.', '.', '9', '3', '.', '.',
//  '2', '9', '.', '.', '.', '.', '1', '.', '6'
//};
//
//char * board = "9.4....13..39........68.9......3.6.1..2...7..5.1.2......6.51........93..29....1.6";
//
//
//"..5.....6"
//"....14..."
//"........."
//".....92.."
//"5....2..."
//".......3."
//"...54...."
//"3.....42."
//"...27.6.."
