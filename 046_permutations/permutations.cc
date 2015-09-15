/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_set>
#include <algorithm>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > permute(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution, DFS with a set, not so good.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > permute(std::vector<int> & nums) {
      std::vector<std::vector<int> > permutations;
      std::vector<int> permutation;
      permute(permutations, permutation, nums);
      return permutations;
    }
  private:
    std::unordered_set<int> us;
    void permute(std::vector<std::vector<int> > & permutations, std::vector<int> & permutation, std::vector<int> & nums) {
      if (permutation.size() == nums.size()) {
        permutations.push_back(permutation);
        return ;
      }
      for (int i=0; i<nums.size(); ++i)
        if (us.find(i) == us.end()) {
          permutation.push_back(nums[i]);
          us.insert(i);
          permute(permutations, permutation, nums);
          permutation.pop_back();
          us.erase(i);
        }
    }
};

class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > permute(std::vector<int> & nums) {
      std::vector<std::vector<int> > permutations;
      permute(permutations, nums, 0);
      return permutations;
    }
  private:
    void permute(std::vector<std::vector<int> > & permutations, std::vector<int> & nums, int idx) {
      if (idx == nums.size()) {
        permutations.push_back(nums);
        return ;
      }
      /* Put every number in the first place once, and each time 
       * do permutation for the remaining n-1 numbers. */
      for (int i=idx; i<nums.size(); ++i) {
        std::swap(nums[i], nums[idx]);
        permute(permutations, nums, idx+1);
        std::swap(nums[i], nums[idx]);
      }
    }
};

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  for (int i=1; i<argc; ++i)
    iv.push_back(std::atoi(argv[i]));
  std::cout << "\nOriginal vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > permutations = solutions[si]->permute(iv);
    std::cout << "The permutations are: " << std::endl;
    for (size_t i=0; i<permutations.size(); ++i) {
      for (size_t j=0; j<permutations[i].size(); ++j)
        std::cout << ' ' << permutations[i][j];
      std::cout << std::endl;
    }
  }

  return 0;
}
