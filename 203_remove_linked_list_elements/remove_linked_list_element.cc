/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

// Star: 7.4.
// Info.: Try to code it smoothly. Consider not only tail but also head in linked list problems.

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

ListNode * removeElements(ListNode * head, int val) {
  if (head == NULL)
    return NULL;

  ListNode * rtn = NULL;
  ListNode * ln = head;
  while (ln!=NULL && ln->val==val) {
    ListNode * next = ln->next;
    delete ln;
    ln = next;
  }
  if (ln == NULL)
    return NULL;

  rtn = ln;
  ListNode * previous = ln;
  ln = ln->next;
  while (ln) {
    if (ln->val == val) {
      while (ln!=NULL && ln->val==val) {
        ListNode * next = ln->next;
        delete ln;
        ln = next;
      }
      previous->next = ln;
      if (ln == NULL)
        return rtn;
    }
    previous = ln;
    ln = ln->next;
  }

  return rtn;
}

int main(int argc, char * argv[]) {

  if (argc < 3) {
    std::cout << "Please specify the correct parameter." << std::endl;
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

  int element_to_be_removed = std::atoi(argv[argc-1]);
  std::cout << "After removing Element " << element_to_be_removed << ": ";
  printList(removeElements(head, element_to_be_removed));

  return 0;
}
