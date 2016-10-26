/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// Star: 9.2.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "../Profiler.h"

class Solution {
  public:
    virtual int singleNumber(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Refer to https://discuss.leetcode.com/topic/22821/an-general-way-to-handle-all-this-sort-of-questions.
class Solution0 : public Solution {
  public:
    int singleNumber(std::vector<int> & nums) {
      int c0 = 0, c1 = 0;
      for (size_t i = 0; i < nums.size(); ++i) {
        int oc0 = c0;
        c0 = (~c1)&c0&(~nums[i]) | (~c1)&(~c0)&nums[i];
        c1 = c1&(~oc0)&(~nums[i]) | (~c1)&oc0&nums[i];
      }
      return c0 | c1;   // Or c0 ^ c1.
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

  // Get an array.
  std::cout << "Please input the array: ";
  std::vector<int> iv;
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);
  std::cout << "The array you input is: ";
  for (auto itr=iv.begin(); itr!=iv.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The single number is " << solutions[si]->singleNumber(iv) << std::endl << std::endl;
  }

  return 0;
}
