/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

// Star: 

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
    virtual bool isValidBST(TreeNode * root) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    bool isValidBST(TreeNode * root) {
      if (!root) return true;
      if ((root->left && root->left->val>=root->val) ||
          (root->right && root->right->val<=root->val))
        return false;
      return isValidBST(root->left) && isValidBST(root->right);
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
