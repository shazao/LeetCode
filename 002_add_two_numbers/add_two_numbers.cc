/*
You are given two linked lists representing two non-negative numbers. 

The digits are stored in reverse order and each of their nodes contain a single digit. 

Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

// Star: 7.2.
// Info.: One-time pass; Try to code it smoothly.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

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

// Solution 0: A straightforward but not compact one.
//ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
//  if (l1 == NULL)
//    return l2;
//  if (l2 == NULL)
//    return l1;
//
//  ListNode * head = new ListNode(0);
//  ListNode * node = head;
//  int ci = 0;
//  while (l1!=NULL && l2!=NULL) {
//    int sum = l1->val + l2->val + ci;
//    ci = 0;
//    if (sum >= 10) {
//      ci = 1;
//      sum %= 10;
//    }
//    node->val = sum;
//    l1 = l1->next;
//    l2 = l2->next;
//    if (l1==NULL && l2==NULL && ci==0) {
//      node->next = NULL;
//      return head;
//    }
//    node->next = new ListNode(0);
//    node = node->next;
//  }
//
//  if (l1 == NULL)
//    while (l2 != NULL) {
//      int sum = l2->val + ci;
//      ci = 0;
//      if (sum >= 10) {
//        ci = 1;
//        sum %= 10;
//      }
//      node->val = sum;
//      l2 = l2->next;
//      if (l2==NULL && ci==0) {
//        node->next = NULL;
//        return head;
//      }
//      node->next = new ListNode(0);
//      node = node->next;
//    }
//  else
//    while (l1 != NULL) {
//      int sum = l1->val + ci;
//      ci = 0;
//      if (sum >= 10) {
//        ci = 1;
//        sum %= 10;
//      }
//      node->val = sum;
//      l1 = l1->next;
//      if (l1==NULL && ci==0) {
//        node->next = NULL;
//        return head;
//      }
//      node->next = new ListNode(0);
//      node = node->next;
//    }
//  node->val = 1;
//  node->next = NULL;
//  return head;
//}

// Solution 1: A more efficient one from LeetCode Discuss.
ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;

  ListNode * dummy = new ListNode(0);
  ListNode * node = dummy;
  int sum = 0;
  while (l1!=NULL || l2!=NULL) {
    sum /= 10;
    if (l1 != NULL) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2 != NULL) {
      sum += l2->val;
      l2 = l2->next;
    }
    node->next = new ListNode(sum%10);
    node = node->next;
  }
  if (sum/10)
    node->next = new ListNode(1);

  ListNode * result = dummy->next;
  delete dummy;
  return result;
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the first list(Non-digit charater to stop): ";
  ListNode * dummy = new ListNode(0);
  int i;
  ListNode * node = dummy;
  while (std::cin >> i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  ListNode * l1 = dummy->next;

  // Clear the input buffer.
  setbuf(stdin, NULL);
  std::cin.clear();

  std::cout << "Please input the second list(Non-digit charater to stop): ";
  node = dummy;
  while (std::cin >> i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  ListNode * l2 = dummy->next;
  delete dummy;
    
  ListNode * l3 = addTwoNumbers(l1, l2);
  std::cout << "After adding these two lists, we get: " << std::endl;
  printList(l3);

  return 0;
}
