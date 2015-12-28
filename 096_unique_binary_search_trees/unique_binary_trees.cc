/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// Star: 8.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

struct TreeNode {
   int val;
   TreeNode * left;
   TreeNode * right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    virtual int numTrees(int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int numTrees(int n) {
      std::vector<int> rst;
      rst.push_back(1);   // n == 0;
      rst.push_back(1);   // n == 1;
      for (int i=2; i<=n; ++i) {  // Dynamically programming from 2 to n.
        int n_i = 0;
        for (int j=0; j<i; ++j)   // root value == 1, 2, 3, ..., n.
          n_i += rst[j] * rst[i-1-j];
        rst.push_back(n_i);
      }
      return rst.back();
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

  std::cout << "Please input the n: ";
  int n = 0;
  std::cin >> n;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    int n_trees = solutions[si]->numTrees(n);
    std::cout << "There're total " << n_trees << " structurally unique BST's (binary search trees) that store values 1..." 
      << n << " ." << std::endl << std::endl;
  }

  return 0;
}
