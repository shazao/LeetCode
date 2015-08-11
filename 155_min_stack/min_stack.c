/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

As below:

typedef struct {

} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {

}

void minStackPush(MinStack *stack, int element) {

}

void minStackPop(MinStack *stack) {

}

int minStackTop(MinStack *stack) {

}

int minStackGetMin(MinStack *stack) {

}

void minStackDestroy(MinStack *stack) {

}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Star: 7.8.
// Info.: Not passed yet.

//typedef struct ListNode {
//  int val;
//  struct ListNode * previous;
//} ListNode;

typedef struct tagListNode {
  int val;
  struct tagListNode * previous;
} ListNode;

typedef struct {
  int * stk;
  int top;
  ListNode * min;
  int max_size;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
  stack->stk = (int *)malloc(sizeof(int) * maxSize);
  stack->top = -1;
  //ListNode * min = (ListNode *)malloc(sizeof(ListNode));      // Note 0: min is initialized to NULL.
  //min->val = INT_MAX;
  //min->previous = NULL;
  stack->min = NULL;
  stack->max_size = maxSize;
}

void minStackPush(MinStack *stack, int element) {
  if (stack->top < stack->max_size-1) {
    stack->stk[++stack->top] = element;
    if (stack->min==NULL || element<=stack->min->val) {    // Note 1: Check whether the pointer is NULL or not before using it!!! At least, consider this issue in mind!
      ListNode * new_min = (ListNode *)malloc(sizeof(ListNode));
      new_min->val = element;
      new_min->previous = stack->min;
      stack->min = new_min;
    }
  }
}

void minStackPop(MinStack *stack) {
  if (stack->top >= 0) {
    if (stack->stk[stack->top] == stack->min->val) {
      ListNode * tmp_min = stack->min;
      stack->min = stack->min->previous;
      free(tmp_min);
    }
    stack->top --;
  }
}

int minStackTop(MinStack *stack) {
  if (stack->top >= 0)
    return stack->stk[stack->top];
  else
    return INT_MAX;
}

int minStackGetMin(MinStack *stack) {
  if (stack->min != NULL)
    return stack->min->val;
  else
    return INT_MIN;
}

void minStackDestroy(MinStack *stack) {   // Note 2: Arrange the deallocating correctly.
  if (stack == NULL)
    return;

  if (stack->stk != NULL)
    free(stack->stk);
  ListNode * ln = stack->min;
  while (ln != NULL) {
    ListNode * tmp = ln;    // Note the order.
    ln = ln->previous;
    free(tmp);       // Don't use a pointer after you freed it.
  }
  free(stack);      // Free stack at last.
  //stack = NULL;
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    printf("Please specify the correct arguments.\n");
    return 0;
  }

  MinStack * ms = (MinStack *)malloc(sizeof(MinStack));
  minStackCreate(ms, 5);
  minStackPush(ms, 3);
  minStackPush(ms, 1);
  minStackPush(ms, 5);
  minStackPush(ms, 0);
  minStackPush(ms, 2);

  printf("Orignal min. is %d.\n", minStackGetMin(ms));
  int i = 0;
  for(; i<5; ++i) {
    printf("After pop %d, ", minStackTop(ms));
    minStackPop(ms);
    printf("min. is %d.\n", minStackGetMin(ms));
  }
  minStackPush(ms, -3);
  printf("After push -3, min. is %d.\n", minStackGetMin(ms));
  minStackDestroy(ms);

  //MinStack * ams = (MinStack *)malloc(sizeof(MinStack));
  //minStackCreate(ams, 2);
  //minStackPush(ams, -3);
  //printf("After push -3, min. is %d.\n", minStackGetMin(ams));

  return 0;
}
