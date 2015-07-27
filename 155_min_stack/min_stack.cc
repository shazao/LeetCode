/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
    void push(int x) {
        
    }

    void pop() {
        
    }

    int top() {
        
    }

    int getMin() {
        
    }
};
*/

// Star: 7.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
#include <climits>

class MinStack {
  public:
    void push(int x) {
      stk_.push(x);
      if (stk_min_.empty()==true || stk_min_.top()>=x)     // Note : ">=". Or "if (getMin() >= x)", better.
        stk_min_.push(x);
    }
    void pop() {
      if (stk_.empty() == false) {
        if (stk_min_.empty()==false && stk_min_.top()==stk_.top())    // Note 0: Check empty() before using top().
          stk_min_.pop();
        stk_.pop();
      }
    }
    int top() {
      if (stk_.empty() == false)
        return stk_.top();
      else
        return INT_MIN;
    }
    int getMin() {
      if (stk_min_.empty() == false)
        return stk_min_.top();
      else
        return INT_MAX;
    }

  private:
    std::stack<int> stk_;
    std::stack<int> stk_min_;
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }


  MinStack ms;
  //ms.push(-3);
  //std::cout << "Current min. is " << ms.getMin() << "." << std::endl;

  //ms.push(2147483646);
  //ms.push(2147483646);
  //ms.push(2147483647);
  //ms.top();
  //ms.pop();
  //ms.getMin();
  //ms.pop();
  //ms.getMin();
  //ms.pop();
  //ms.push(2147483647);
  //ms.top();
  //ms.getMin();
  //ms.push(-2147483648);
  //ms.top();
  //ms.getMin();
  //ms.pop();
  //ms.getMin();

  ms.push(0);
  ms.push(1);
  ms.push(0);
  std::cout << ms.getMin() << std::endl;
  ms.pop();
  std::cout << ms.getMin() << std::endl;

  return 0;
}
