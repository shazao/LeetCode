/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

// Star: 8.8.
// TODO: Figure out the iterative solution.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual TreeNode * constructBtFromPreorderInorderTraversal(std::vector<int> & preorder, std::vector<int> & inorder) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution; Beats 58.13%.
class Solution0 : public Solution {
  public:
    TreeNode * constructBtFromPreorderInorderTraversal(std::vector<int> & preorder, std::vector<int> & inorder) {
      if (preorder.empty() || inorder.empty()) return NULL;
      size_t ps = preorder.size(), is = inorder.size();
      if (ps != is) return NULL;
      size_t root_idx = 0;
      return constructBtFromPreorderInorderTraversal(preorder, inorder, root_idx, 0, ps);
    }
  private:
    TreeNode * constructBtFromPreorderInorderTraversal(std::vector<int> & preorder, std::vector<int> & inorder,
                                                       size_t & root_idx, size_t l, size_t r) {
      int root_value = preorder[root_idx];
      size_t i = l;
      for (; i<r; ++i)
        if (inorder[i] == root_value)
          break;
      TreeNode * root = new TreeNode(root_value);
      if (i > l)
        root->left = constructBtFromPreorderInorderTraversal(preorder, inorder, ++root_idx, l, i);
      if (r > i+1)
        root->right = constructBtFromPreorderInorderTraversal(preorder, inorder, ++root_idx, i+1, r);
      return root;
    }
};

// Iterative solution from LeetCode Discuss; Beats 92.35%.
class Solution1 : public Solution {
  public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
      int i = 0, j = 0;
      TreeNode * root = new TreeNode(0x80000000);
      TreeNode * pp = NULL, * ptr = root;
      std::stack<TreeNode*> sn;
      sn.push(root);
      while (j < in.size()) {
          if (sn.top()->val == in[j]) {
            pp=sn.top();
            sn.pop();
            j++;
          } else if (pp) {
            ptr=new TreeNode(pre[i]);
            pp->right=ptr;pp=NULL;
            sn.push(ptr);
            i++;
          } else {
            ptr=new TreeNode(pre[i]);
            sn.top()->left=ptr;
            sn.push(ptr);
            i++;
          }
      }
      ptr=root->left;
      delete root;
      return ptr;
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
