/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 

the linked list should become 1 -> 2 -> 4 after calling your function.
*/

// Star: 6.5.
// Info.: Try to write it smoothly by hand.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

void deleteNode(ListNode * node) {
  if (node == NULL)
    return;

  ListNode * ln = node;
  while (ln->next->next != NULL) {    // "Except the tail" implies the list has two nodes at least.
    ln->val = ln->next->val;
    ln = ln->next;
  }

  ListNode * tail = ln->next;
  ln->val = tail->val;
  ln->next = NULL;
  delete tail;

  return;
}

ListNode * findNode(ListNode * head, int val) {
  if (head == NULL)
    return NULL;

  ListNode * ln = head;
  while (ln != NULL)
    if (ln->val == val)
      return ln;
    else
      ln = ln->next;

  return NULL;
}

int main(int argc, char * argv[]) {

  if (argc < 3) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  ListNode * head = new ListNode(std::atoi(argv[1]));

  ListNode * node = head;
  for (int i=0; i<argc-3; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(std::atoi(argv[i+2]));
  }
  std::cout << "Original list: ";
  printList(head);

  int val_to_be_deleted = std::atoi(argv[argc-1]);
  ListNode * node_to_be_deleted = findNode(head, val_to_be_deleted);

  std::cout << "After delete (first) " << val_to_be_deleted << ": ";
  deleteNode(node_to_be_deleted);
  printList(head);

  return 0;
}
