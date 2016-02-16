/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

// Star: 8.8.
// Info.: Quite interesting, similar to LeetCode 098.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual void flatten(TreeNode * root) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution.
class Solution0 : public Solution {
  public:
    void flatten(TreeNode * root) {
      TreeNode * previous = NULL;
      flatten(root, previous);
      return;
    }
  private:
    void flatten(TreeNode * root, TreeNode * & previous) {
      if (root) {
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        if (left == NULL) previous = root;
        root->left = NULL;
        root->right = left;
        flatten(left, previous);
        previous->right = right;
        flatten(right, previous);
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
