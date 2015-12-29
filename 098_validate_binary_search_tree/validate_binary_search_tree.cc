/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

// Star: 9.0.
// Info.: Refer to LeetCode 110.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <climits>
#include "..\Profiler.h"

struct TreeNode {
   int val;
   TreeNode * left;
   TreeNode * right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    virtual bool isValidBST(TreeNode * root) = 0; // Pure virtual, or Solutionx may not have data members.
    virtual bool isValidBST(TreeNode * tn, long * min, long * max) = 0;
};

// My solution inpired by LeetCode 110.
class Solution0 : public Solution {
  public:
    bool isValidBST(TreeNode * root) {
      if (!root) return true;
      long min = LONG_MAX, max = LONG_MIN;
      return isValidBST(root, &min, &max);
    }

  private:
    bool isValidBST(TreeNode * tn, long * min, long * max) {
      if (!tn) return true;

      long l_min = LONG_MAX;
      long l_max = LONG_MIN;
      long r_min = LONG_MAX;
      long r_max = LONG_MIN;

      if (isValidBST(tn->left, &l_min, &l_max) == false)
        return false;
      if (isValidBST(tn->right, &r_min, &r_max) == false)
        return false;
      
      int cv = tn->val;   // Current value.
      *min = l_min<r_min ? l_min : r_min;
      *min = *min<cv ? *min : cv;
      *max = l_max>r_max ? l_max : r_max;
      *max = *max>cv ? *max : cv;

      if (cv <= l_max || cv >= r_min) return false;
      return true;
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
