/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

// Star: 7.5.

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

class Solution {
  public:
    virtual ListNode * rotateRight(ListNode * head, int k) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    ListNode * rotateRight(ListNode * head, int k) {
      if (head==NULL || head->next==NULL)
        return head;

      size_t length = 1;
      ListNode * node = head;
      while (node->next) {
        node = node->next;
        ++ length;
      }
      node->next = head;

      if (k %= length)
        for (int i=0; i<length-k; ++i)
          node = node->next;

      ListNode * new_head = node->next;
      node->next = NULL;
      return new_head;
    }
};

// From LeetCode Discuss, seems it does not get benefit.
class Solution1 : public Solution {
  public:
    ListNode * rotateRight(ListNode * head, int k) {
        if(!k || !head || !head->next)
          return head;

        ListNode * fast = head;
        int lens = 1;
        while (k--) {   // Note 0: Postfix decrement here!
          if(fast->next) {
            fast = fast->next;
            lens ++;
          } else {
            fast = head;
            k %= lens;
          }
        }

        if (fast == head)
          return head;
        ListNode * slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode * newhead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newhead;
    }
};

void printList(ListNode * head) {
  if (head == NULL)
    return;

  ListNode * node = head;
  while (node->next) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << node->val << std::endl;
}

ListNode * duplicateList(ListNode * head) {
  if (head == NULL) return head;

  ListNode * node = head;
  ListNode * dummy = new ListNode(0);
  ListNode * duplicated_list_node = dummy;
  while (node) {
    duplicated_list_node->next = new ListNode(node->val);
    node = node->next;
    duplicated_list_node = duplicated_list_node->next;
  }

  ListNode * duplicated_list_head = dummy->next;
  delete dummy;
  return duplicated_list_head;
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the rotation displacement and the list: ";
  int k = 0;
  std::cin >> k;

  ListNode * dummy = new ListNode(0);
  int i;
  ListNode * node = dummy;
  while (std::cin >> i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  ListNode * l1 = dummy->next;
  delete dummy;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  ListNode * dl1 = duplicateList(l1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    if (si == 0) {
      std::cout << "Original list: "; printList(l1);
      std::cout << "Rotated list: "; printList(solutions[si]->rotateRight(l1, k));
    } else if (si == 1) {
      std::cout << "Original list: "; printList(dl1);
      std::cout << "Rotated list: "; printList(solutions[si]->rotateRight(dl1, k));
    } else {
    }
    std::cout << std::endl;
  }

  return 0;
}
