/*
Write an efficient algorithm that searches for a value in an m x n matrix. 

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

// Star: 8.
// Info.: It's a good case to learn Binary Search.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual bool searchMatrix(std::vector<std::vector<int> > & matrix, int target) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Passed the judge at the 2nd time.
// And quite efficient.
class Solution0 : public Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int> > & matrix, int target) {
      size_t m = matrix.size();
      size_t n = matrix[0].size();

      if (target>matrix[m-1][n-1] || target<matrix[0][0])
        return false;
      // Binary search Column 0.
      int l = 0, r = m - 1;
      int mm = 0;
      while (l <= r) {
        mm = l + ((r-l)>>1);
        if (matrix[mm][0] > target)
          r = mm - 1;
        else {
          if (matrix[mm][n-1] >= target)
            break;
          l = mm + 1;
        }
      }
      // Binary search corresponding row.
      l = 0; r = n - 1;
      while (l <= r) {
        int mid = l + ((r-l)>>1);
        if (matrix[mm][mid] == target)
          return true;
        else if (matrix[mm][mid] > target)
          r = mid - 1;
        else
          l = mid + 1;
      }
      return false;
    }
};

// Solution from LeetCode Discuss, which I think less efficient.
// And it's truly less efficient.
class Solution1 : public Solution {
  public:
    bool searchMatrix(std::vector<std::vector<int> > & matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();

      if (target>matrix[m-1][n-1] || target<matrix[0][0])
        return false;

      // Just do binary search one time.
      int l = 0, r = m*n - 1;
      while (l <= r) {
        int middle = l + ((r-l)>>1);
        int mm = matrix[middle/n][middle%n];
        if (mm == target)
          return true;
        else if (mm < target)
          l = middle + 1;
        else
          r = middle - 1;
      }
      return false;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<std::vector<int> > matrix;
  std::cout << "Please input a matrix: " << std::endl;
  int i = 0;
  while (! std::cin.eof()) {
    std::vector<int> row;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> i)
      row.push_back(i);
    if (row.empty())
      break;
    if (matrix.size()!=0 && row.size()!=matrix[matrix.size()-1].size()) {
      std::cout << "Distorted matrix!" << std::endl;
      return -1;
    } else
      matrix.push_back(row);
  }
  std::cout << "\nThe matrix you gave is: " << std::endl;
  for (size_t i=0; i<matrix.size(); ++i) {
    for (size_t j=0; j<matrix[i].size(); ++j)
      std::cout << ' ' << matrix[i][j];
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Please input the target: ";
  int target;
  std::cin >> target;
  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The matrix above " << (solutions[si]->searchMatrix(matrix, target)?"contains ":"doesn't contain ")
      << target << '.' << std::endl << std::endl;
  }

  return 0;
}
