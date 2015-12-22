/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

// Star: 8.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head) {
  ListNode * node = head;
  while (node) {
    std::cout << node->val << ' ';
    node = node->next;
  }
  std::cout << std::endl;
}

class Solution {
  public:
    virtual ListNode * reverseBetween(ListNode * head, int m, int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    ListNode * reverseBetween(ListNode * head, int m, int n) {
      if (head==NULL || head->next==NULL) return head;

      size_t n_step = 1;
      ListNode * front = head;
      ListNode * back = NULL;
      while (n_step < m) {
        back = front;
        front = front->next;
        ++ n_step;
      }
      ListNode * cut0 = back;
      ListNode * cut1 = front;
      while (n_step <= n) {   // Note: Do not use increment operator.
        ListNode * next = front->next;
        front->next = back;
        back = front;
        front = next;
        ++ n_step;
      }
      cut1->next = front;
      if (cut0) {
        cut0->next = back;
        return head;
      } else return back;
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
  std::cout << "Please input the list(Non-digit charater to stop): ";
  ListNode * dummy = new ListNode(0);
  int i;
  ListNode * node = dummy;
  while (std::cin >> i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  ListNode * l = dummy->next;
  delete dummy;
  std::cout << "The linked list you input: ";
  printList(l);
  std::cout << std::endl;

  // Get m and n.
  std::cin.clear();
  std::cin.sync();
  std::cout << "Please input the m and n between which the list is reversed: ";
  int m = 1, n = 1;
  std::cin >> m >> n;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    ListNode * reversedListHead = solutions[si]->reverseBetween(l, m, n);
    std::cout << "After reversing the list between " << m << " and " << n << ": ";
    printList(reversedListHead);
    std::cout << std::endl;
  }

  return 0;
}
