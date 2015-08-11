/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:
A:          a1  a2
                  \
                    c1 c2 c3
                  /
B:      b1  b2  b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

// Star: 7.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution 0: A easy-to-understand method.
//ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
//  if (headA==NULL || headB==NULL)
//    return NULL;
//
//  ListNode * lna = headA;
//  ListNode * lnb = headB;
//  int la = 1;
//  int lb = 1;
//  while (lna->next != NULL) {
//    ++ la;
//    lna = lna->next;
//  }
//  while (lnb->next != NULL) {
//    ++ lb;
//    lnb = lnb->next;
//  }
//
//  if (lna != lnb)
//    return NULL;
//
//  lna = headA;
//  lnb = headB;
//  int dl = la>lb ? la-lb : lb-la;
//  if (la > lb)
//    while (dl-- > 0)
//      lna = lna->next;
//  else
//    while (dl-- > 0)
//      lnb = lnb->next;
//
//  while (lna != lnb) {
//    lna = lna->next;
//    lnb = lnb->next;
//  }
//
//  return lna;
//}

// Solution 1: A smarter method from LeetCode. (But slower according to the LeetCode Online Judge. Why?)
ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
  if (headA==NULL || headB==NULL)
    return NULL;

  ListNode * ln1 = headA;
  ListNode * ln2 = headB;

  while (ln1!=NULL && ln2!=NULL) {
    ln1 = ln1->next;
    ln2 = ln2->next;
  }
  if (ln1 == NULL)
    ln1 = headB;
  else
    ln2 = headA;

  while (ln1!=NULL && ln2!=NULL) {
    ln1 = ln1->next;
    ln2 = ln2->next;
  }
  if (ln1 == NULL)
    ln1 = headB;
  else
    ln2 = headA;

  while (ln1 != ln2) {
    ln1 = ln1->next;
    ln2 = ln2->next;
  }

  return ln1;
}

void printList(ListNode * head) {
  ListNode * node = head;
  while (node->next) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << node->val << std::endl;
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  ListNode * l1 = new ListNode(0);
  ListNode * node1 = l1;
  for (int i=1; i<=5; ++i) {
    while (node1->next)
      node1 = node1->next;
    node1->next = new ListNode(i);
  }
  printList(l1);

  ListNode * l2 = new ListNode(0);
  ListNode * node2 = l2;
  for (int i=1; i<=3; ++i) {
    while (node2->next)
      node2 = node2->next;
    node2->next = new ListNode(i);
  }
  //node2->next->next = node1->next;
  node2->next->next = node1;
  printList(l2);

  std::cout << "The intersection node of two lists above is " << getIntersectionNode(l1, l2)->val << "." << std::endl;

  return 0;
}
