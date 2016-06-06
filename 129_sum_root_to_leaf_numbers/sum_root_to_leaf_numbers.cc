/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

// Star: 8.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual  = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    Solution0() : sum_(0) { }
    int sumNumbers(TreeNode * root) {
      if (!root) return 0;
      path_.push_back(root->val);
      if (root->left==NULL && root->right==NULL) {
        for (int power=1, i=path_.size()-1; i>=0; --i) {
          sum_ += path_[i] * power;
          power *= 10;
        }
      }
      if (root->left) sumNumbers(root->left);
      if (root->right) sumNumbers(root->right);
      path_.pop_back();
      return sum_;
    }

  private:
    int sum_;
    std::vector<int> path_;
};

class Solution1 : public Solution {
  public:
    int sumNumbers(TreeNode * root) {
      return sumNumbersUtil(root, 0);
    }

  private:
    int sumNumbersUtil(TreeNode * tn, int sum) {
      if (!tn) return 0;
      if (tn->left || tn->right) return sumNumbersUtil(tn->left, sum*10+tn->val) + sumNumbersUtil(tn->right, sum*10+tn->val);
      else return sum*10 + tn->val;
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
