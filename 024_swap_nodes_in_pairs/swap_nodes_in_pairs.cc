/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

// Star: 7.5.
// Info.: One-time pass; Try to solve it using a iterative method.
// The recursive method is like "reverse a linked list" and quite interesting.

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

// Recursion violates constant space requirement, right?
ListNode * swapPairs(ListNode * head) {
  if (head==NULL || head->next==NULL)
    return head;
  ListNode * to_be_processed = head->next->next;
  ListNode * new_head = head->next;
  head->next->next = head;
  head->next = swapPairs(to_be_processed);
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

  head = swapPairs(head);
  std::cout << "List after swapping every two adjacent nodes is: ";
  printList(head);

  return 0;
}

// Some iterative solutions form LeetCode Discuss.

// 0:
// As you can see, the addition of an empty node at the start removes the problem of "head" being a special case.
/*
public class Solution {
  public ListNode swapPairs(ListNode head) {
    ListNode start = new ListNode(0); //make head no longer a special case
    start.next = head;

    for(ListNode cur = start; cur.next != null && cur.next.next != null; cur = cur.next.next) {
      cur.next = swap(cur.next, cur.next.next);        
    }
    return start.next;
  }
  private Listnode swap(ListNode next1, ListNode next2) {
    next1.next = next2.next;
    next2.next = next1;
    return next2;
  }
}
*/

// 1:
// Quite nice.
/*
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **p = &head;

        while (*p && (*p)->next) {
            ListNode *t = (*p)->next;

            (*p)->next = t->next;
            t->next = *p;
            *p = t;

            p = &(*p)->next->next;
        }

        return head;
    }
};
*/
