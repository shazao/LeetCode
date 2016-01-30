/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual TreeNode * sortedArrayToBST(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    TreeNode * sortedArrayToBST(std::vector<int> & nums) {
      if (nums.empty()) return NULL;
      return sortedArrayToBST(nums, 0, nums.size());
    }
  private:
    TreeNode * sortedArrayToBST(std::vector<int> & nums, int l, int r) {
      int m = l + (r-l)/2;
      TreeNode * root = new TreeNode(nums[m]);
      if (m > l) root->left = sortedArrayToBST(nums, l, m);
      if (r > m+1) root->right = sortedArrayToBST(nums, m+1, r);
      return root;
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

  // Get an array.
  std::cout << "Please input the array: ";
  std::vector<int> iv;
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);
  std::cout << "The array you input is: ";
  for (auto itr=iv.begin(); itr!=iv.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    solutions[si]->;
  }

  return 0;
}
