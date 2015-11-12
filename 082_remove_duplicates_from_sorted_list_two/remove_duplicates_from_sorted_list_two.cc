/* 
Given a sorted linked list, delete all nodes that have duplicate numbers, 

leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

// Star: 8.9.
// Info.: Another good example of recursion of singly linked list.

#include <iostream>
#include <vector>
#include "..\Profiler.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head) {
  ListNode * node = head;
  while (node) {
    std::cout << ' ' << node->val;
    node = node->next;
  }
  std::cout << std::endl;
}

class Solution {
  public:
    virtual ListNode * deleteDuplicates(ListNode * head) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    ListNode * deleteDuplicates(ListNode * head) {
      if (!head || !head->next)
        return head;
      int val = head->val;
      if (val != head->next->val) {
        head->next = deleteDuplicates(head->next);
        return head;
      } else {
        head = head->next;
        while (head && head->val==val) {
          ListNode * tmp = head;
          head = head->next;
          delete tmp;
        }
        return deleteDuplicates(head);
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

  // Get one linked list.
  std::cout << "Please input the list: ";
  ListNode * dummy = new ListNode(0);
  int i;
  ListNode * node = dummy;
  while (std::cin >> i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  ListNode * l = dummy->next;
  delete dummy;
  std::cout << "The list you input is: ";
  printList(l);

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The linked list after removing duplicates is: ";
    printList(solutions[si]->deleteDuplicates(l));
    std::cout << std::endl;
  }

  return 0;
}

