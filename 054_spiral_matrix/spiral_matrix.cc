/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

// Star: 8.7.
// Info.: A clear solution from LeetCode Discuss.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<int> spiralOrder(std::vector<std::vector<int>> & matrix) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> & matrix) {
      if (matrix.empty()) return {};

      int m = matrix.size();
      int n = matrix[0].size();
      
      // Top , right, bottom, left.
      int t=0, r=n-1, b=m-1, l=0;
      std::vector<int> result;
      while (true) {
        for (int col=l; col<=r; ++col) result.push_back(matrix[t][col]);
        if (++t > b) break;
        for (int row=t; row<=b; ++row) result.push_back(matrix[row][r]);
        if (--r < l) break;
        for (int col=r; col>=l; --col) result.push_back(matrix[b][col]);
        if (--b < t) break;
        for (int row=b; row>=t; --row) result.push_back(matrix[row][l]);
        if (++l > r) break;
      }
      return result;
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
    std::vector<int> spiral_order = solutions[si]->spiralOrder(matrix);
    std::cout << "\nThe spiral order of the matrix above:";
    for (size_t i=0; i<spiral_order.size(); ++i)
      std::cout << ' ' << spiral_order[i];
    std::cout << std::endl << std::endl;
  }

  return 0;
}
