/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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

void inOrder(TreeNode * tn) {
  if (!tn) return;
  inOrder(tn->left);
  std::cout << ' ' << tn->val;
  inOrder(tn->right);
}

class Solution {
  public:
    virtual std::vector<TreeNode*> generateTrees(int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<TreeNode*> generateTrees(int n) {
      std::vector<std::vector<TreeNode*> > trees;
      trees.push_back(std::vector<TreeNode*>(1, NULL));
      for (int i=1; i<=n; ++i) {    // Dynamic programming.
        std::vector<TreeNode*> next_trees;
        for (int j=1; j<=i; ++j) {  // Everyone can be the root.
          for (int k=0; k<trees[j-1].size(); ++k)
            for (int l=0; l<trees[i-j].size(); ++l) {
              TreeNode * root = new TreeNode(j);
              root->left = copyTree(trees[j-1][k]);
              root->right = copyTree(trees[i-j][l], j);
              next_trees.push_back(root);
            }
        }
        trees.push_back(next_trees);
      }
      return trees.back();
    }
  private:
    TreeNode * copyTree(TreeNode * root, int offset = 0) {
      if (!root) return root;
      TreeNode * new_root = new TreeNode(root->val + offset);
      new_root->left = copyTree(root->left);
      new_root->right = copyTree(root->right);
      return new_root;
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
    std::vector<TreeNode*> all_trees = solutions[si]->generateTrees(n);
    std::cout << "The in-order traversal of all the trees are: " << std::endl;
    for (size_t i=0; i<all_trees.size(); ++i) {
      inOrder(all_trees[i]);
      std::cout << std::endl;
    }
    std::cout << "Total " << all_trees.size() << std::endl;
  }

  return 0;
}
