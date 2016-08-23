/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

// Star: 9.0.
// Info.: One-time pass.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<std::string> > partition(std::string s) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<std::vector<std::string> > partition(std::string s) {
      std::vector<std::vector<std::string> > rst;
      if (s.empty()) return rst;
      std::vector<std::string> one_pass;
      backtracking(rst, one_pass, s, 0);
      return rst;
    }
  private:
    void backtracking(std::vector<std::vector<std::string> > & rst, std::vector<std::string> & one_pass, std::string & s, size_t begin_idx) {
      if (begin_idx == s.size()) rst.push_back(one_pass);
      for (size_t length=1; length<=s.size()-begin_idx; ++length)
        if (isPalindrome(s, begin_idx, begin_idx+length)) {
          one_pass.push_back(s.substr(begin_idx, length));
          backtracking(rst, one_pass, s, begin_idx + length);
          one_pass.pop_back();
        }
    }
    bool isPalindrome(std::string & s, size_t b, size_t e) {
      if (e <= b) return false;
      -- e;
      while (e > b)
        if (s[b++] != s[e--])
          return false;
      return true;
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

  std::cout << "Please give me a string: " << std::endl;
  std::string s;
  std::cin >> s;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  std::vector<std::vector<std::string> > rst;
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    rst.clear();
    rst = solutions[si]->partition(s);
    std::cout << "The partitioned palindrome strings are: " << std::endl;
    for (auto it0=rst.begin(), e0=rst.end(); it0!=e0; ++it0) {
      for (auto it1=it0->begin(), e1=it0->end(); it1!=e1; ++it1)
        std::cout << *it1 << ' ';
      std::cout << std::endl;
    }
  }

  return 0;
}
