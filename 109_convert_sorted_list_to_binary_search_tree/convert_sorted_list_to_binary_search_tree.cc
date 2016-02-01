/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

// Star: 9.3.
// TODO: Review & recode.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual TreeNode * sortedListToBST(ListNode * head) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Solution from LeetCode Discuss, quite smart, but not so efficient.
// Beats only 5.91%.
class Solution0 : public Solution {
  public:
    TreeNode * sortedListToBST(ListNode * head) {
      size_t len = 0;
      ListNode * ln = head;
      while (ln) {
        ++ len;
        ln = ln->next;
      }
      ListNode * inorder_node = head;
      return sortedListToBST(inorder_node, len);
    }
  private:
    TreeNode * sortedListToBST(ListNode * & inorder_node, size_t len) {
      if (!len) return NULL;
      TreeNode * tn = new TreeNode(0);
      tn->left = sortedListToBST(inorder_node, len/2);
      tn->val = inorder_node->val;
      inorder_node = inorder_node->next;
      tn->right = sortedListToBST(inorder_node, len - len/2 -1);
      return tn;
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
