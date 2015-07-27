/* Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists. */

// Star: 7.5.
// Use legacy in LeetCode019.
// Info.: 30 minutes, one-time pass.

#include <iostream>

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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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

int main() {

  std::cout << "Original list: ";

  ListNode * l1 = new ListNode(1);
  ListNode * node = l1;
  for (int i=0; i<=5; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(2*i + 1);
  }
  printList(l1);

  ListNode * l2 = new ListNode(1);
  node = l2;
  for (int i=1; i<=7; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(2*i);
  }
  printList(l2);

  std::cout << "Merged list: ";
  printList(mergeTwoLists(l1, l2));

  return 0;
}
