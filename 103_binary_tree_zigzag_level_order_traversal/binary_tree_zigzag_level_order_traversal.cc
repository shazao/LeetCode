/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

// Star: 8.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > zigzagLevelOrder(TreeNode * root) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > zigzagLevelOrder(TreeNode * root) {
      std::vector<std::vector<int> > rst;
      if (!root) return rst;
      std::stack<TreeNode*> stk0;
      std::stack<TreeNode*> stk1;
      stk0.push(root);
      int direction = 0;
      std::stack<TreeNode*> * cs = &stk0;     // current stack
      std::stack<TreeNode*> * ns = &stk1;     // next stack
      while (!cs->empty()) {
          std::vector<int> one_level;
          while (!cs->empty()) {
              TreeNode * tn = cs->top();
              one_level.push_back(tn->val);
              if (direction) {
                  if (TreeNode * right = tn->right) ns->push(right);
                  if (TreeNode * left = tn->left) ns->push(left);
              } else {
                  if (TreeNode * left = tn->left) ns->push(left);
                  if (TreeNode * right = tn->right) ns->push(right);
              }
              cs->pop();
          }
          rst.push_back(one_level);
          direction ^= 1;
          std::swap(cs, ns);
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
