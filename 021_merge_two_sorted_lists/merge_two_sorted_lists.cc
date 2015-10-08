/* Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists. */

// Star: 7.5.
// Use legacy in LeetCode019.
// Info.: 30 minutes, one-time pass.

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
  while (node->next) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << node->val << std::endl;
}

class Solution {
  public:
    virtual ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution.
class Solution0 : public Solution {
  public:
    ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == NULL)
        return l2;
      if (l2 == NULL)
        return l1;

      ListNode * node1 = l1;
      ListNode * node2 = l2;

      ListNode * head = l1;
      if (l1->val > l2->val) {
        head = l2;
        node2 = l2->next;
      } else 
        node1 = l1->next;

      ListNode * node = head;
      while (node1 && node2) {
        if (node1->val < node2->val) {
          node->next = node1;
          node1 = node1->next;
        } else {
          node->next = node2;
          node2 = node2->next;
        }
        node = node->next;
      }
      if (node1 == NULL)
        node->next = node2;
      else
        node->next = node1;

      return head;
    }
};

// A cleaner one from LeetCode Discuss.
class Solution1 : public Solution {
  public:
    ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == NULL)
        return l2;
      if (l2 == NULL)
        return l1;

      ListNode * dummy = new ListNode(0);
      ListNode * tail = dummy;

      while (l1 && l2) {
        if (l1->val < l2->val) {
          tail->next = l1;
          l1 = l1->next;
        } else {
          tail->next = l2;
          l2 = l2->next;
        }
        tail = tail->next;
      }

      tail->next = l1 ? l1 : l2;

      ListNode * result = dummy->next;
      delete dummy;
      return result;
    }
};

// Recursive method.
class Solution2 : public Solution {
  public:
    ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == NULL)
        return l2;
      if (l2 == NULL)
        return l1;

      if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
      } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
      }
    }
};

static ListNode * l1 = NULL;
static ListNode * l2 = NULL;

void createLists() {
  std::cout << "Original list: " << std::endl;

  l1 = new ListNode(1);
  ListNode * node = l1;
  for (int i=0; i<=5; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(2*i + 1);
  }
  printList(l1);

  l2 = new ListNode(1);
  node = l2;
  for (int i=1; i<=7; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(2*i);
  }
  printList(l2);
}

void deleteList(ListNode * l) {
  while (l) {
    ListNode * next = l->next;
    delete l;
    l = next;
  }
}

int main() {

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  Solution2 s2; solutions.push_back(&s2);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    createLists();
    std::cout << "Merged list: ";
    Profiler perf;
    ListNode * sl = solutions[si]->mergeTwoLists(l1, l2);
    printList(sl);
    deleteList(sl);
  }
  return 0;
}
