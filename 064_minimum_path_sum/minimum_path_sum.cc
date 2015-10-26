/*
Given a m x n grid filled with non-negative numbers, find a path from 

top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

// Star: 8.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int minPathSum(std::vector<std::vector<int> > & grid) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int minPathSum(std::vector<std::vector<int> > & grid) {
      size_t m = grid.size();
      size_t n = grid[0].size();
      std::vector<int> sum_column(m, grid[0][0]);
      for (size_t i=1; i<m; ++i)
        sum_column[i] = sum_column[i-1] + grid[i][0];
      for (size_t j=1; j<n; ++j) {
        sum_column[0] += grid[0][j];
        for (size_t i=1; i<m; ++i)
          sum_column[i] = (sum_column[i]>sum_column[i-1]?sum_column[i-1]:sum_column[i]) + grid[i][j];
      }
      return sum_column[m-1];
    }
};

class Solution1 : public Solution {
  public:
    
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

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << solutions[si]->minPathSum(matrix) << std::endl << std::endl;
  }

  return 0;
}
