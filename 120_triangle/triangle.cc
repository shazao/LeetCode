/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

// Star: 8.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int minimumTotal(std::vector<std::vector<int> > & triangle) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int minimumTotal(std::vector<std::vector<int> > & triangle) {
      if (triangle.empty()) return -1;
      std::vector<int> iv(triangle[triangle.size()-1]);
      for (int i=triangle.size()-2; i>=0; --i) {
        for (int j=0; j<triangle[i].size(); ++j) {
          int a = triangle[i][j] + iv[j];
          int b = triangle[i][j] + iv[j+1];
          iv[j] = a>b ? b : a;
        }
      }
      return iv[0];
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

  std::vector<std::vector<int> > triangle;
  triangle.push_back(std::vector<int>({1}));
  triangle.push_back(std::vector<int>({3, 1}));
  triangle.push_back(std::vector<int>({6, 5, 1}));
  triangle.push_back(std::vector<int>({4, 1, 8, 3}));

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The minimum sum of " << std::endl;
    for (int i=0; i<triangle.size(); ++i) {
      std::cout << std::string(triangle.size()-1-i, ' ');
      for (int j=0; j<triangle[i].size(); ++j)
        std::cout << ' ' << triangle[i][j];
      std::cout << std::endl;
    }
    std::cout << "from top to bottom is: " << solutions[si]->minimumTotal(triangle) << std::endl << std::endl;
  }

  return 0;
}
