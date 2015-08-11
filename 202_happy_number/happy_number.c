/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

// Star: 7.
// Info.: All unhappy numbers will get into the loop 4->16->37 ...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int squareSum(int n) {
  n = n<0 ? -n : n;
  int sum = 0;
  while (n) {
    int mod = n%10;
    sum += mod*mod;
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  int sum = 0;
  while (1) {
    sum = squareSum(n);
    //printf("%d\n", sum);
    if (sum == 1)
      return true;
    if (sum==4 || sum==0)
      return false;
    n = sum;
  };
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  int n = atoi(argv[1]);
  printf("%d %s a happy number.\n", n, isHappy(n)?"is":"is not");

}
