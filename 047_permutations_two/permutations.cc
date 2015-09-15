/*

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
    virtual std::vector<std::vector<int> > permuteUnique(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Wrong solution.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > permuteUnique(std::vector<int> & nums) {
      std::vector<std::vector<int> > permutations;
      std::sort(nums.begin(), nums.end());
      permuteUnique(permutations, nums, 0);
      return permutations;
    }
  private:
    void permuteUnique(std::vector<std::vector<int> > & permutations, std::vector<int> & nums, int idx) {
      if (idx == nums.size()) {
        permutations.push_back(nums);
        return ;
      }
      /* Put every number in the first place once, and each time 
       * do permutation for the remaining n-1 numbers. */
      for (int i=idx; i<nums.size(); ++i) {
        if (i==idx || nums[i]!=nums[i-1]) {
          std::swap(nums[i], nums[idx]);
          int next_idx = idx+1;
          while (nums[next_idx] != nums[i]) ++next_idx;
            permuteUnique(permutations, nums, next_idx);
          std::swap(nums[i], nums[idx]);
        }
      }
    }
};

/* Nice code! I take quite a long time to understand this. 
 * In each loop, the num[i+1:] can keep its order as well. That's real interesting! */
class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > permuteUnique(std::vector<int> & nums) {
      std::vector<std::vector<int> > permutations;
      std::sort(nums.begin(), nums.end());
      permuteUnique(nums, 0, nums.size(), permutations);
      return permutations;
    }
  private:
    void permuteUnique(std::vector<int> nums, int i, int j, std::vector<std::vector<int> > & permutations) {
      if (i == j-1) {
          permutations.push_back(nums);
          return;
      }
      for (int k = i; k < j; k++) {
          if (i != k && nums[i] == nums[k]) continue;
          std::swap(nums[i], nums[k]);
          permuteUnique(nums, i+1, j, permutations);
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
    std::vector<std::vector<int> > permutations = solutions[si]->permuteUnique(iv);
    std::cout << "The permutations are: " << std::endl;
    for (size_t i=0; i<permutations.size(); ++i) {
      for (size_t j=0; j<permutations[i].size(); ++j)
        std::cout << ' ' << permutations[i][j];
      std::cout << std::endl;
    }
    std::cout << "Total " << permutations.size() << std::endl;
  }

  return 0;
}
