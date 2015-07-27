/* Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass. */

#include <iostream>

// Star: 7.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head == NULL)
    return head;
  if (head->next == NULL) {
    delete head;
    return NULL;
  }

  ListNode * front = head;
  ListNode * rear = head;
  ListNode * previous = head;
  int count = 0;
  while (front->next) {
    front = front->next;
    ++ count;
    if (count >= n) {
      previous = rear;
      rear = rear->next;
    }
  }
  if (rear == head)     // Note 0.
    head = head->next;
  previous->next = rear->next;
  delete rear;
  return head;
}

void printList(ListNode * head) {
  ListNode * node = head;
  while (node->next) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << node->val << std::endl;
}

int main() {

  ListNode * head = new ListNode(1);

  ListNode * node = head;
  for (int i=2; i<=5; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(i);
  }
  std::cout << "Original list: ";
  printList(head);

  int n = 5;
  std::cout << "After removing " << n << "th node from end of list: ";
  printList(removeNthFromEnd(head, n));

  return 0;
}
