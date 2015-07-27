/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not. */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

// Star: 6.5.

bool isValid(std::string s) {
  std::stack<char> st;
  for (size_t i=0; i<s.length(); ++i) {
    char c = s[i];
    if (c=='(' || c=='[' || c=='{')
      st.push(c);
    else if (c==')' || c==']' || c=='}') {
      if (st.empty())         // Note 1: Cause by Note 0(crucial).
        return false;

      if (c == ')')
        if (st.top() != '(')        // Note 0.
          return false;
        else 
          st.pop();
      else if (c == ']')
        if (st.top() != '[')
          return false;
        else 
          st.pop();
      else if (c == '}')
        if (st.top() != '{')
          return false;
        else 
          st.pop();
    }
  }
  if (st.size() > 0) 
    return false;

  return true;
}


int main() {

  std::vector<std::string> sv;
  sv.push_back("");
  sv.push_back("()");
  sv.push_back("()[]{}");
  sv.push_back("(]");
  sv.push_back("([)]");

  for (int i=0; i<sv.size(); ++i)
    std::cout << "'" << sv[i] << "' " << (isValid(sv[i]) ? "is " : "is not ") << "valid." << std::endl;

  return 0;
}
