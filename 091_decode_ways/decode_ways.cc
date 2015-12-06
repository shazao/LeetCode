/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

// Star: 8.9.
// Info.: Recursive method is usually not a good way to DP problem?

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int numDecodings(std::string s) = 0; // Pure virtual, or Solutionx may not have data members.
};

/* My solution, revised many times according to the fail infomation; 
 * But still failed at 188/259: "10".
 * So, it demonstrates recursive method is not suitable for DP problem. */
class Solution0 : public Solution {
  public:
    int numDecodings(std::string s) {
      if (s.empty() || !(s[0]>='1' && s[0]<='9')) return 0;
      const char * cs = s.c_str();
      while (*cs && cs[1]) {
        if (*cs=='0' && cs[1]=='0')
          return 0;
        ++ cs;
      }
      return nDecodings(s.c_str());
    }

  private:
    int nDecodings(const char * s) {
      if (!s[0] || !s[1]) return 1;
      if (s[1] == '0')
        if (s[2]) return nDecodings(s+2);
        else return 0;
      if (*s=='0' || *s>='3') return nDecodings(s+1);
      if (s[1] > '6') return nDecodings(s+2);
      return nDecodings(s+1) + nDecodings(s+2);
    }
};

// A solution form LeetCode Discuss.
class Solution1 : public Solution {
  public:
    int numDecodings(std::string s) {
      if (s.empty()) return 0;
      size_t n = s.size();
      std::vector<int> memo(n+1);
      memo[n] = 1;
      memo[n-1] = s[n-1]=='0' ? 0 : 1;
      for (int i=n-2; i>=0; --i) {
        if (s[i] == '0') continue;
        memo[i] = (s[i]-'0')*10 + s[i+1]-'0' <= 26 ? memo[i+1] + memo[i+2] :
                                                     memo[i+1];
      }
      return memo[0];
    }
};

// Another solution from LeetCode Discuss, less straightforward.
class Solution2 : public Solution {
  public:
    int numDecodings(std::string s) {
      if (s.empty()) return 0;
      int n2 = 1;     // Note 0.
      int n1 = s[0]=='0' ? 0 : 1;
      for (size_t i=1; i<s.size(); ++i) {
        if (s[i] == '0') n1 = 0;
        if (s[i-1]=='1' || s[i-1]=='2'&&s[i]<='6') {
          int n1_ = n1;
          n1 = n1 + n2;
          n2 = n1_;
        } else        // Note 1.
          n2 = n1;
      }
      return n1;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get an array.
  std::cout << "Please input the digits string: ";
  std::string s;
  std::cin >> s;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  Solution2 s2; solutions.push_back(&s2);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "There're total " << solutions[si]->numDecodings(s) << " decoding ways of the digits string above." 
      << std::endl << std::endl;
  }

  return 0;
}
