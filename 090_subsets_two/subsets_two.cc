/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

// Star: 9.0.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > subsetsWithDup(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// A smart solution from LeetCode Discuss.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> & nums) {
      std::vector<std::vector<int> > rst(1, std::vector<int>());
      std::sort(nums.begin(), nums.end());
      size_t size = nums.size();
      for (size_t i=0; i<size; ) {
        int n_duplicates = 1;
        while (n_duplicates+i<size && nums[n_duplicates+i]==nums[i])
          ++ n_duplicates;
        size_t n_sets = rst.size();
        for (size_t j=0; j<n_sets; ++j) {
          std::vector<int> tmp(rst[j]);
          for (size_t k=0; k<n_duplicates; ++k) {
            tmp.push_back(nums[i]);
            rst.push_back(tmp);
          }
        }
        i += n_duplicates;
      }
      return rst;
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
    std::vector<std::vector<int> > subsets = solutions[si]->subsetsWithDup(iv);
    std::cout << "The subsets of array above are: " << std::endl;
    for (size_t i=0; i<subsets.size(); ++i) {
      for (size_t j=0; j<subsets[i].size(); ++j)
        std::cout << ' ' << subsets[i][j];
      std::cout << std::endl;
    }
    std::cout << "Total " << subsets.size() << std::endl << std::endl;
  }

  return 0;
}
