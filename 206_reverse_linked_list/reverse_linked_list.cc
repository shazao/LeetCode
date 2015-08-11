/*
Reverse a singly linked list.
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

// Solution 0: Iteratively.
ListNode * reverseListIteratively(ListNode * head) {
  if (head==NULL || head->next==NULL)
    return head;

  ListNode * front = head->next;
  ListNode * back = head;
  back->next = NULL;

  while (front != NULL) {
    ListNode * tmp = front->next;
    front->next = back;
    back = front;
    front = tmp;
  }

  return back;
}

// Solution 1: Recursively.
ListNode * reverseListRecusively(ListNode * head) {
  if (head==NULL || head->next==NULL)
    return head;

  ListNode * new_head = reverseListRecusively(head->next);
  head->next->next = head;
  head->next = NULL;

  return new_head;
}

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
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

  std::cout << "Iteratively reversed list: ";
  ListNode * irs = reverseListIteratively(head);
  printList(irs);

  std::cout << "Again recursively reversed list: ";
  ListNode * rrs = reverseListRecusively(irs);
  printList(rrs);

  return 0;
}

// A tighter iteratively solution.
//ListNode* reverseList(ListNode* head) {
//    ListNode* pre = NULL;
//    while (head) {
//        ListNode* next = head -> next;
//        head -> next = pre;
//        pre = head;
//        head = next;
//    } 
//    return pre;
//}
