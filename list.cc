/*

*/

// Star: 

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

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  ListNode * head = new ListNode(std::atoi(argv[1]));

  ListNode * node = head;
  for (int i=0; i<argc-2; ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(std::atoi(argv[i+2]));
  }
  std::cout << "Original list: ";
  printList(head);

  return 0;
}
