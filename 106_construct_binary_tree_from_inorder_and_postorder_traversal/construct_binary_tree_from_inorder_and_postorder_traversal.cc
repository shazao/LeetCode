/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

// Star: 8.8.
// Info: Similar to LeetCode 105.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual TreeNode * buildTree(std::vector<int> & inorder, std::vector<int> & postorder) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution.
class Solution0 : public Solution {
  public:
    TreeNode * buildTree(std::vector<int> & inorder, std::vector<int> & postorder) {
      if (inorder.empty()) return NULL;
      int root_idx = postorder.size() - 1;
      return buildTree(inorder, postorder, 0, root_idx, root_idx);
    }
  private:
    TreeNode * buildTree(std::vector<int> & inorder, std::vector<int> & postorder, 
                         int l, int r, int & root_idx) {
      int root_value = postorder[root_idx];
      int i = r;
      for (; i>=0; --i)
        if (inorder[i] == root_value)
          break;
      TreeNode * root = new TreeNode(root_value);
      if (r >= i+1) root->right = buildTree(inorder, postorder, i+1, r, --root_idx);
      if (i-1 >= l) root->left = buildTree(inorder, postorder, l, i-1, --root_idx);
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
