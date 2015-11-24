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

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int numDecodings(std::string s) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution, revised many times according to the fail infomation;
// But still failed at 188/259: "10".
/*
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
*/

class Solution1 : public Solution {
  public:
    
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
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "There're total " << solutions[si]->numDecodings(s) << " decoding ways of the digits string above." 
      << std::endl << std::endl;
  }

  return 0;
}
