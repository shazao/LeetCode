/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

// Star: 8.8.
// Info.: Quite interesting.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > subsets(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Recursive solution.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > subsets(std::vector<int> & nums) {
      std::sort(nums.begin(), nums.end());
      subsets(nums, 0);
      return subsets_;
    }

  private:
    std::vector<std::vector<int> > subsets_;
    std::vector<int> set_;

    void subsets(std::vector<int> & nums, int idx) {
      subsets_.push_back(set_);
      for (size_t i=idx; i<nums.size(); ++i) {
        set_.push_back(nums[i]);
        subsets(nums, i+1);
        set_.pop_back();
      }
    }
};

// Iterative solution.
class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > subsets(std::vector<int> & nums) {
      std::vector<std::vector<int> > subsets(1, std::vector<int>(0));
      std::sort(nums.begin(), nums.end());
      for (size_t i=0; i<nums.size(); ++i) {
        size_t size = subsets.size();
        for (size_t j=0; j<size; ++j) {   // subsets.push_back(subsets[j]); subsets.back().push_back(nums[i]);
          std::vector<int> tmp(subsets[j]);
          tmp.push_back(nums[i]);
          subsets.push_back(tmp);
        }
      }
      return subsets;
    }
};

// Bit manipulation.
class Solution2 : public Solution {
  public:
    std::vector<std::vector<int> > subsets(std::vector<int> & nums) {
      size_t n = nums.size();
      size_t nn = 1LL<<n;
      std::sort(nums.begin(), nums.end());
      std::vector<std::vector<int> > subsets(nn, std::vector<int>());
      for (size_t i=0; i<nn; ++i)
        for (size_t j=0; j<n; ++j)
          if ((i>>j)&0x01)
            subsets[i].push_back(nums[j]);
      return subsets;
    }
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
  Solution1 s1; solutions.push_back(&s1);
  Solution2 s2; solutions.push_back(&s2);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > subsets = solutions[si]->subsets(iv);
    std::cout << "The subsets of array above are: " << std::endl;
    for (size_t i=0; i<subsets.size(); ++i) {
      for (size_t j=0; j<subsets[i].size(); ++j)
        std::cout << ' ' << subsets[i][j];
      std::cout << std::endl;
    }
    std::cout << "Total " << subsets.size() << " sets." << std::endl;
  }

  return 0;
}
