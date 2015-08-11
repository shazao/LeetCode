/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner.
Rectangle 0: (A, B), (C, D);
Rectangle 1: (E, F), (G, H).
Assume that the total area is never beyond the maximum possible value of int..
*/

// Star: 7.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int area = (C-A)*(D-B) + (G-E)*(H-F);
  int x_l = max(A, E);
  int y_l = max(B, F);
  int x_r = min(C, G);
  int y_r = min(D, H);
  if (x_l>x_r || y_l>y_r)
    return area;
  else
    return area - (x_r-x_l)*(y_r-y_l);
}

void main(int argc, char * argv[]) {

  if (argc != 9) {
    printf("Please specify the correct parameter.\n");
    return;
  }

  int area = computeArea(
                  atoi(argv[1]),
                  atoi(argv[2]),
                  atoi(argv[3]),
                  atoi(argv[4]),
                  atoi(argv[5]),
                  atoi(argv[6]),
                  atoi(argv[7]),
                  atoi(argv[8])
                  );
  printf ("Area covered by these two rectangles is %d.\n", area);

}
