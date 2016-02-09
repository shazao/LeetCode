/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

// Star: 8.2.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
 {
    virtual std::vector<std::vector<int> > pathSum(TreeNode * root, int sum) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > pathSum(TreeNode * root, int sum) {
      std::vector<std::vector<int> > paths;
      if (root == NULL) return paths;
      std::vector<int> path;
      pathSum(paths, path, root, sum);
      return paths;
    }
  private:
    void pathSum(std::vector<std::vector<int> > & paths, std::vector<int> & path, TreeNode * tn, int sum) {
      path.push_back(tn->val);
      if (tn->left==NULL && tn->right==NULL)
        if (tn->val == sum)
          paths.push_back(path);

      sum -= tn->val;

      if (TreeNode * left = tn->left)
        pathSum(paths, path, left, sum);
      if (TreeNode * right = tn->right)
        pathSum(paths, path, right, sum);

      path.pop_back();
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
