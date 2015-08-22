/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 

n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

// Star: 7.9.
// Info.: Don't know how to solve it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Solution 0: My solution after looking the spoiler, but still got TLE
// (Probably also got wrong answer: don't go on searching from both sides at the same time).
//int maxArea(int * height, int heightSize) {
//  int area = 0;
//  int l = 0;
//  int r = heightSize - 1;
//  while (l < r) {
//    int new_area = (r-l) * (height[l]<height[r] ? height[l] : height[r]);
//    area = new_area>area ? new_area : area;
//    int i = l;
//    while (height[++i]<=height[l] && i<heightSize);
//    if (i != heightSize)
//      l = i;
//    int j = r;
//    while (height[--j]<=height[r] && j>=0);
//    if (j >= 0)
//      r = j;
//    if (i==heightSize && j<0)
//      return area;
//  }
//  return area;
//}

// Solution 1: A solution from spoiler.
//int maxArea(int * height, int heightSize) {
//  int area = 0;
//  int l = 0;
//  int r = heightSize - 1;
//  while (l < r) {
//    int new_area = (r-l) * (height[l]<height[r] ? height[l] : height[r]);
//    area = new_area>area ? new_area : area;
//    if (height[l] < height[r]) {    // Note 0: Going on from the smaller one side.
//      int i = l;
//      while (++i<r && height[i]<=height[l]);
//      if (i != r)
//        l = i;
//      else
//        return area;
//    } else {
//      int i = r;
//      while (--i>l && height[i]<=height[r]);
//      if (i != l)
//        r = i;
//      else
//        return area;
//    }
//  }
//  return area;
//}

// Solution 2: A solution from LeetCode Discuss, which I think is less time efficient than Solution 1.
int maxArea(int * height, int heightSize) {
  int area = 0;
  int l = 0;
  int r = heightSize - 1;
  while (l < r) {
    int new_area = (r-l) * (height[l]<height[r] ? height[l] : height[r]);
    area = new_area>area ? new_area : area;
    if (height[l] < height[r])    // Note 0: Going on from the smaller one side.
      ++ l;
    else
      -- r;
  }
  return area;
}

void main(int argc, char * argv[]) {

  if (argc < 2) {
    printf("Please specify the correct arguments.\n");
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

  printf("The container with most water has a lateral area: %d.\n", maxArea(arr, argc-1));

  free(arr);
}
