/* You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

// Star: 7.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Version 0: Not efficient("Time Limit Exceeded").
//int climbStairs(int n) {
//
//  if (n == 1)       // Note 0: Termination condition(Acctually, for all the recursive functions).
//    return 1;
//  if (n == 2)
//    return 2;
//
//  int nw = 0;
//  return nw += climbStairs(n-1) + climbStairs(n-2);   // "+ climbStairs(n-2)", not "+ 2*climbStairs(n-2)".
//
//}

// Version 1: Fabonacci sequence.
int climbStairs(int n) {

  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  int a = 1;
  int b =2;
  int i = 3;
  int nw = 0;
  for (; i<=n; ++i) {
    nw = a + b;
    a = b;
    b = nw;
  }

  return nw;

}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct parameter.\n");
    return 0;
  }

  int n = atoi(argv[1]);
  printf("You have %d distinct ways to climb to the top of a %d-step stair case.\n(You can either climb 1 or 2 steps each time.)\n", climbStairs(n), n);

  return 0;
}
