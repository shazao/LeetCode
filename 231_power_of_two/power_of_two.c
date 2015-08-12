/*
Given an integer, write a function to determine if it is a power of two.
*/

// Star: 7.
// Info.: Met it before.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
  if (n <= 0)
    return false;

  n &= n-1;
  if (n)
    return false;
  else
    return true;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  int n = atoi(argv[1]);

  printf("%d is %spower of two.\n", n, isPowerOfTwo(n)?"":"not ");

}
