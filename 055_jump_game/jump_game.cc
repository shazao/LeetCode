/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

// Star: 8.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual bool canJump(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// From LeetCode Discuss.
class Solution0 : public Solution {
  public:
    bool canJump(std::vector<int> & nums) {
      size_t i = 0;
      for (size_t reach=0; i<nums.size() && i<=reach; ++i)
        reach = reach<(i+nums[i]) ? i+nums[i] : reach;
      return i == nums.size();
    }
};

// Start from the end, from LeetCode Discuss.
class Solution1 : public Solution {
  public:
    bool canJump(std::vector<int> & nums) {
      int frontier = nums.size()-1;
      int i=nums.size()-2;
      for (; i>=0; --i)
        frontier = i+nums[i]>=frontier ? i : frontier;
      return frontier <= 0;
    }
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the array: ";
  int i;
  std::vector<int> iv;
  while (std::cin >> i)
    iv.push_back(i);

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "You can " << (solutions[si]->canJump(iv) ? "" : "not ")
      << "jump to the end!" << std::endl << std::endl;
  }

  return 0;
}
