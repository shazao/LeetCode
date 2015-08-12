/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

// Star: 7.3.
// Info.: Quite interesting.

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

ListNode * reverseLinkedList(ListNode * head) {
  if (head==NULL || head->next==NULL)
    return head;

  ListNode * previous = head;
  ListNode * node = head->next;
  head->next = NULL;
  while (node) {
    ListNode * next = node->next;
    node->next = previous;
    previous = node;
    node = next;
  }

  return previous;
}

bool isPalindrome(ListNode * head) {
  if (head==NULL || head->next==NULL)
    return true;

  ListNode * slow = head;
  ListNode * fast = head;
  while (fast->next!=NULL && fast->next->next!=NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  fast = reverseLinkedList(slow->next);
  ListNode * tail = fast;
  slow = head;
  while (fast!=NULL)
    if (fast->val != slow->val) {
      reverseLinkedList(tail);
      return false;
    } else {
      fast = fast->next;
      slow = slow->next;
    }

  reverseLinkedList(tail);
  return true;
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

  std::cout << "This singly linked list " << (isPalindrome(head)?"is ":"is not ") << "palindrome." << std::endl;

  printList(head);

  return 0;
}
