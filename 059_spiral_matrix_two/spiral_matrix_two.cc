/*
Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

// Star: 8.7.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > generateMatrix(int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

// From LeetCode Discuss.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > generateMatrix(int n) {
      std::vector<std::vector<int> > matrix(n, std::vector<int>(n));
      int i = 0, j = 0, k = 1;
      while (k <= n*n) {
        // Row, left to right.
        j = i;
        while (j < n-i) matrix[i][j++] = k++;

        // Column, top to bottom.
        j = i + 1;
        while (j < n-i) matrix[j++][n-1-i] = k++;

        // Row, right to left.
        j = n - 2 - i;
        while (j >= i) matrix[n-1-i][j--] = k++;

        // Column, bottom to top.
        j = n - 2 - i;
        while (j > i) matrix[j--][i] = k++;

        // Next layer.
        ++ i;
      }
      return matrix;
    }
};

class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > generateMatrix(int n) {
      std::vector<std::vector<int> > matrix(n, std::vector<int>(n));
      // Top, bottom, left, right.
      int t = 0, b = n-1, l = 0, r = n-1;
      int i = 1;
      while (i <= n*n) {
        // Top row.
        for (int column=l; column<=r; ++column)
          matrix[t][column] = i++;
        ++ t;

        // Right column.
        for (int row=t; row<=b; ++row)
          matrix[row][r] = i++;
        -- r;

        // Bottom row.
        for (int column=r; column>=l; --column)
          matrix[b][column] = i++;
        -- b;

        // Left column.
        for (int row=b; row>=t; --row)
          matrix[row][l] = i++;
        ++ l;
      }
      return matrix;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int n = atoi(argv[1]);

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > matrix = solutions[si]->generateMatrix(n);
    for (size_t i=0; i<matrix.size(); ++i) {
      for (size_t j=0; j<matrix[i].size(); ++j)
        std::cout << ' ' << matrix[i][j];
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
