/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

// Star: 7.8.
// Info.: Don't know how to solve.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int max(int a, int b) {
  return a>b ? a : b;
}

int rob(int* nums, int numsSize) {
  if (numsSize == 0)
    return 0;
  if (numsSize == 1)
    return nums[0];
  if (numsSize == 2)
    return max(nums[0], nums[1]);

  int * max_money = (int *)malloc(sizeof(int) * numsSize);

  max_money[0] = nums[0];
  max_money[1] = max(nums[0], nums[1]);
  int i = 2;
  for (; i<numsSize; ++i)
    max_money[i] = max(max_money[i-1], nums[i]+max_money[i-2]);

  int rtn = max_money[i-1];
  free(max_money);

  return rtn;
}

void main(int argc, char * argv[]) {

  if (argc < 2) {
    printf("Please specify the correct parameter.\n");
    return;
  }

  int i = 0;
  int * arr = (int *)malloc(sizeof(int)*(argc-1));
  for (; i<argc-1; ++i)
    arr[i] = atoi(argv[i+1]);
  printf("Array: ");
  for (i=0; i<argc-1; ++i)
    printf("%d ", arr[i]);
  printf("\n");

  printf("Maximum money I can rob is %d.\n", rob(arr, argc-1));

  free(arr);
}
