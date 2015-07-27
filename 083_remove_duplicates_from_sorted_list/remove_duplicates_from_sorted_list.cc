/* Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. */

// Star: 7.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head) {
  ListNode * node = head;
  while (node->next) {
    printf("%d ", node->val);
    //std::cout << node->val << " ";
    node = node->next;
  }
  printf("%d\n", node->val);
  //std::cout << node->val << std::endl;
}

struct ListNode * deleteDuplicates(struct ListNode * head) {

  if (head==NULL || head->next==NULL)
    return head;
    
  ListNode * previous = head;
  ListNode * node = head->next;
  while (node) {
    while (node->val == previous->val) {
      ListNode * tmp = node;
      node = node->next;
      free(tmp);
      if (node == NULL)
        break;
    }
    previous->next = node;
    previous = node;
    if (node)             // Node 0: Let node point to its succssor, or it'll be freed!
      node = node->next;
  }

  return head;

}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct parameter.\n");
    return 0;
  }

  ListNode * l = new ListNode(argv[1][0] - '0');
  ListNode * node = l;
  for (int i=1; i<strlen(argv[1]); ++i) {
    while (node->next)
      node = node->next;
    node->next = new ListNode(argv[1][i] - '0');
  }
  printf("Original list:\n");
  printList(l);

  printf("Stripped list:\n");
  printList(deleteDuplicates(l));

  return 0;
}
