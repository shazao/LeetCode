/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

// Star: 9.
// Info.: Don't know how to solve it elegantly;
//        Sipmle problems usually have simple solutions;
//        How to do it when unticlockwise.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "..\Profiler.h"

class Solution {
  public:
    virtual void rotate(std::vector<std::vector<int> > & matrix) = 0; // Pure virtual, or Solutionx may not have data members.
};

// From LeetCode Discuss.
// First reverse up to down, then swap the symmetry
class Solution0 : public Solution {
  public:
    void rotate(std::vector<std::vector<int> > & matrix) {
      reverse(matrix.begin(), matrix.end());
      for (size_t i=0; i<matrix.size(); ++i)
        for (size_t j=i+1; j<matrix[i].size(); ++j)   // Note 0: How to swap the symmetrical elements.
          std::swap(matrix[i][j], matrix[j][i]);
    }
    
};

class Solution1 : public Solution {
  public:
    
};

void printMatrix(std::vector<std::vector<int> > & m) {
  for (size_t i=0; i<m.size(); ++i) {
    for (size_t j=0; j<m[i].size(); ++j)
      std::cout << ' ' << m[i][j];
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<std::vector<int> > matrix;
  matrix.push_back(std::vector<int>({1, 2, 3}));
  matrix.push_back(std::vector<int>({4, 5, 6}));
  matrix.push_back(std::vector<int>({7, 8, 9}));
  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  std::cout << "Original image: " << std::endl;
  printMatrix(matrix);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    solutions[si]->rotate(matrix);
    std::cout << "Rotated image: " << std::endl;
    printMatrix(matrix);
  }

  return 0;
}
