/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

// Star: 9.1.

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
    virtual std::vector<int> inorderTraversal(TreeNode * root) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution, not so neat.
class Solution0 : public Solution {
public:
  std::vector<int> inorderTraversal(TreeNode * root) {
    std::vector<int> rst;
    if (!root) return rst;
    TreeNode * node = root;
    std::stack<TreeNode*> stk;
    while (!stk.empty() || node) {
      while (node) {
        stk.push(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      rst.push_back(node->val);
      if (TreeNode * right = node->right) {
        node = right;
      } else {
        if (!stk.empty()) {
          TreeNode * parent = stk.top();
          stk.pop();
          rst.push_back(parent->val);
          node = parent->right;
        } else node = NULL;
      }
    }
    return rst;
  }
};

// Using stack, Method 1.
class Solution1 : public Solution {
public:
  std::vector<int> inorderTraversal(TreeNode * root) {
    std::vector<int> rst;
    if (!root) return rst;
    TreeNode * node = root;
    std::stack<TreeNode*> stk;
    while (!stk.empty() || node) {
      if (node) {
        stk.push(node);
        node = node->left;
      } else {
        rst.push_back(stk.top()->val);
        node = stk.top()->right;
        stk.pop();
      }
    }
    return rst;
  }
};

// Using stack, Method 2.
class Solution2 : public Solution {
 std::vector<int> inorderTraversal(TreeNode * root) {
    std::vector<int> rst;
    if (!root) return rst;
    std::stack<TreeNode*> stk;
    while (1) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      if (stk.empty()) break;
      rst.push_back(stk.top()->val);
      root = stk.top()->right;
      stk.pop();
    }
    return rst;
  }   
};

// Morris traversal.
class Solution3 : public Solution {
public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> rst;
    TreeNode * cn = root;   // Current node.
    while (cn) {
      if (cn->left == NULL) {
        rst.push_back(cn->val);
        cn = cn->right;
      } else {
        TreeNode * node = cn->left;
        while (node->right!=NULL && node->right!=cn)
          node = node->right;
        if (node->right == NULL) {
          node->right = cn;
          cn = cn->left;
        } else {
          rst.push_back(cn->val);
          cn = cn->right;
          node->right = NULL;
        }
      }
    }
    return rst;
  }
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
