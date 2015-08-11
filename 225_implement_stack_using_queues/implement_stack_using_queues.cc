/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, 
and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or 
deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>

class Stack {
  public:
    // Push element x onto stack.
    void push(int x) {
      q.push(x);
    }
    // Removes the element on top of the stack.
    void pop() {
      for (size_t i=0; i<q.size()-1; ++i) {
        q.push(q.front());
        q.pop();
      }
      q.pop();
    }
    // Get the top element.
    int top() {
      return q.back();
    }
    // Return whether the stack is empty.
    bool empty() {
      return q.empty();
    }
  private:
    std::queue<int> q;
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  Stack s;

  for (int i=0; i<4; ++i) {
    s.push(i);
    std::cout << "Pushed " << i << std::endl;
    std::cout << "Top: " << s.top() << std::endl;
  }

  s.pop();
  std::cout << "Popped." << std::endl;
  std::cout << "Top: " << s.top() << std::endl;
  s.push(-1);
  std::cout << "Pushed -1." << std::endl;
  std::cout << "Top: " << s.top() << std::endl;

  for (int i=0; i<4; ++i) {
    s.pop();
    std::cout << "Popped." << std::endl;
  }

  std::cout << "Now it's " << (s.empty()?"":"not ") << "empty." << std::endl;

  return 0;
}
