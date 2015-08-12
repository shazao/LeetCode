/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, 
peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. 
You may simulate a stack by using a list or deque (double-ended queue), 
as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, 
no pop or peek operations will be called on an empty queue).
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>

class Queue {
  public:
    // Push element x to the back of queue.
    void push(int x) {
      stk_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
      //if (!stk_out.empty())
      //  stk_out.pop();
      //else {
      //  while (! stk_in.empty()) {
      //    stk_out.push(stk_in.top());
      //    stk_in.pop();
      //  }
      //  stk_out.pop();
      //}
      peek();     // Avoid duplicating code.
      stk_out.pop();
    }

    // Get the front element.
    int peek(void) {
      //if (!stk_out.empty())
      //  return stk_out.top();
      //else {
      //  while (! stk_in.empty()) {
      //    stk_out.push(stk_in.top());
      //    stk_in.pop();
      //  }
      //  return stk_out.top();
      //}
      if (stk_out.empty())      // Neater.
        while (! stk_in.empty())
          stk_out.push(stk_in.top()), stk_in.pop();
      return stk_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
      return stk_in.empty() && stk_out.empty();
    }
  private:
    std::stack<int> stk_in;
    std::stack<int> stk_out;
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  Queue q;

  for (int i=0; i<4; ++i) {
    q.push(i);
    std::cout << "Pushed " << i << ". (Top: " << q.peek() << ")" << std::endl;
  }

  q.pop();
  std::cout << "Popped" << ". (Top: " << q.peek() << ")" << std::endl;
  int i = -1;
  q.push(i);
  std::cout << "Pushed " << i << ". (Top: " << q.peek() << ")" << std::endl;

  for (int i=0; i<4; ++i) {
    q.pop();
    std::cout << "Popped." ;
    if (! q.empty())
      std::cout << " (Top: " << q.peek() << ")" << std::endl;
  }

  std::cout << std::endl << "Now the queue " << (q.empty()?"is ":"is not ") << "empty." << std::endl;

  return 0;
}
