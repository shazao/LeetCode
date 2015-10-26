/*
Given a m x n matrix, if an element is 0, 

set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

// Star: 7.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual void setZeroes(std::vector<std::vector<int> > & matrix) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    void setZeroes(std::vector<std::vector<int> > & matrix) {
      size_t m = matrix.size();
      size_t n = matrix[0].size();
      bool column0_zero = false;
      // Memorize zeroes.
      for (size_t i=0; i<m; ++i) {
        if (matrix[i][0] == 0)
          column0_zero = true;
        for (size_t j=1; j<n; ++j) 
          if (matrix[i][j] == 0)
            matrix[0][j] = matrix[i][0] = 0;
      }
      // Set zeroes.
      for (int i=m-1; i>=0; --i) {
        for (int j=n-1; j>0; --j)
          if (matrix[i][0]==0 || matrix[0][j]==0)
            matrix[i][j] = 0;
        if (column0_zero)   // Must be put here(After resetting matrix[i][j](j >= 1)).
          matrix[i][0] = 0;
      }
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
    solutions[si]->setZeroes(matrix);
    std::cout << "After setting zeroes: " << std::endl;
    for (size_t i=0; i<matrix.size(); ++i) {
      for (size_t j=0; j<matrix[i].size(); ++j)
        std::cout << ' ' << matrix[i][j];
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
