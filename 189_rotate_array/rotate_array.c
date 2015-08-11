/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

// Star: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Solution 0.
//void rotate(int* nums, int numsSize, int k) {
//  if (numsSize<=0 || k<=0)
//    return;
//  k = k%numsSize;
//  if (k == 0)
//    return;
//
//  int i = 0;
//  int * new_arr = (int *)malloc(sizeof(int)*numsSize);
//  for (i=0; i<k; ++i)
//    new_arr[i] = nums[numsSize-k+i];
//  for (i=numsSize-1; i>=k; --i)   // Note 0: From tail to head.
//    nums[i] = nums[i-k];
//  for (i=0; i<k; ++i)
//    nums[i] = new_arr[i];
//
//  free(new_arr);
//}

// Solution 1: In-place.
void swap(int * a, int * b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse(int * arr, int b, int e) {
  if (arr == NULL)
    return;

  while (b < e)
    swap(arr+b++, arr+e--);
}

void rotate(int * nums, int numsSize, int k) {
  if (numsSize<=0 || k<=0)
    return;
  k = k%numsSize;
  if (k == 0)
    return;

  // Rotate the array around the axis which is just before the kth element from the end.
  // For example, 1 2 3 4 5 | 6 7, k=2, two lines below rotate the array
  // around the axis between '5' and '6'.
  reverse(nums, 0, numsSize-1-k);
  reverse(nums, numsSize-k, numsSize-1);

  // Reverse the array.
  reverse(nums, 0, numsSize-1);
}

void main(int argc, char * argv[]) {

  if (argc < 3) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  int i = 0;

  int * arr = (int *)malloc(sizeof(int)*(argc-2));
  for (i=0; i<argc-2; ++i)
    arr[i] = atoi(argv[i+1]);
  printf("Original array: ");
  for (i=0; i<argc-2; ++i)
    printf("%d ", arr[i]);
  printf("\n");

  rotate(arr, argc-2, atoi(argv[argc-1]));

  printf("Rotated array: ");
  for (i=0; i<argc-2; ++i)
    printf("%d ", arr[i]);
  printf("\n");

  free(arr);

}
