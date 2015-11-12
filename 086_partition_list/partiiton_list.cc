/*
Given a linked list and a value x, partition it such that 

all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

// Star: 9.0.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head) {
  while (head) {
    std::cout << ' ' << head->val;
    head = head->next;
  }
  std::cout << std::endl;
}

class Solution {
  public:
    virtual ListNode * partition(ListNode * head, int x) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    ListNode * partition(ListNode * head, int x) {
      ListNode * dmy0 = new ListNode(0);
      ListNode * dmy1 = new ListNode(0);
      ListNode * front = dmy0, * back = dmy1;
      while (head) {
        if (head->val < x) {
          front->next = head;
          front = front->next;
        } else {
          back->next = head;
          back = back->next;
        }
        head = head->next;
      }
      front->next = dmy1->next;
      back->next = NULL;
      delete dmy1;
      ListNode * to_be_returned = dmy0->next;
      delete dmy0;
      return to_be_returned;
    }
};

class Solution1 : public Solution {
  public:
    
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get one linked list.
  std::cout << "Please input the list: ";
  ListNode * dummy = new ListNode(0);
  int i;
  ListNode * node = dummy;
  while (std::cin >> i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  ListNode * l = dummy->next;
  delete dummy;
  std::cout << "The list you input is: ";
  printList(l);

  std::cout << "Please input the x:";
  std::cin.clear();
  std::cin.sync();
  int x = 0;
  std::cin >> x;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The list after partitioning is: ";
    printList(solutions[si]->partition(l, x));
    std::cout << std::endl;
  }

  return 0;
}
