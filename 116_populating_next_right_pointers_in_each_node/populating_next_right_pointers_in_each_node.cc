/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

// Star: 8.8.
// Info.: Not bad.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 TreeLinkNode(int x, TreeLinkNode * left, TreeLinkNode * right) : val(x), left(left), right(right), next(NULL) {}
};

class Solution {
  public:
    virtual void connect(TreeLinkNode * root) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Iterative method.
class Solution0 : public Solution {
  public:
    void connect(TreeLinkNode * root) {
      if (root) {
        TreeLinkNode * lmn = root;  // Left most node.
        TreeLinkNode * lln = NULL;  // Last layer node.
        while (lmn->left) {
          lln = lmn;
          while (lln) {
            lln->left->next = lln->right;
            TreeLinkNode * next = lln->next;
            if (next)
              lln->right->next = next->left;
            lln = next;
          }
          lmn = lmn->left;
        }
      }
      return;
    }
};

// Recursive method.
class Solution1 : public Solution {
  public:
    void connect(TreeLinkNode * root) {
      if (root) connect(root->left, root->right);
    }
  private:
    void connect(TreeLinkNode * n0, TreeLinkNode * n1) {
      if (n0 && n1) {
        n0->next = n1;
        connect(n0->left, n0->right);
        connect(n0->right, n1->left);
        connect(n1->left, n1->right);
      }
    }
};

void print(TreeLinkNode * root) {
  if (root) {
    TreeLinkNode * lmn = root;
    while (lmn) {
      TreeLinkNode * tln = lmn;
      while (tln) {
        std::cout << ' ' << tln->val;
        tln = tln->next;
      }
      std::cout << std::endl;
      lmn = lmn->left;
    }
  }
  return ;
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  TreeLinkNode * _3 = new TreeLinkNode(3);
  TreeLinkNode * _4 = new TreeLinkNode(4);
  TreeLinkNode * _5 = new TreeLinkNode(5);
  TreeLinkNode * _6 = new TreeLinkNode(6);
  TreeLinkNode * _1 = new TreeLinkNode(1, _3, _4);
  TreeLinkNode * _2 = new TreeLinkNode(2, _5, _6);
  TreeLinkNode * root = new TreeLinkNode(0, _1, _2);

  std::vector<Solution*> solutions;
  //Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    solutions[si]->connect(root);
    std::cout << "The connected tree: " << std::endl;
    print(root);
  }

  return 0;
}
