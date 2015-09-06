/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

// Star: 8.5.
// Info.: One-time pass, but not so time-efficient(Only beats 4.96% of c++ submissions).
// Info.: Do backtracking with recursion is easier.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > combinationSum(std::vector<int> & candidates, int target);
};

// Solution 0: My solution, a straightforward method.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> & candidates, int target) {
      std::vector<std::vector<int> > combinations;
      sort(candidates.begin(), candidates.end());
      std::vector<int> x(candidates.size(), 0);

      findCombination(candidates, target, x, 0, combinations);

      return combinations;
    }

  private:
    int sum(std::vector<int> & candidates, std::vector<int> & x, int idx) {
      int sum = 0;
      for (int i=0; i<=idx; ++i)
        sum += candidates[i]*x[i];
      return sum;
    }

    void findCombination(std::vector<int> & candidates, int target, std::vector<int> & x, int idx, std::vector<std::vector<int> > & combinations) {
      if (idx == candidates.size())
        return;

      for (int i=0; i<=target/candidates[idx]; ++i) {
        x[idx] = i;
        int s = sum(candidates, x, idx);  // Time exhausting.
        if (s == target) {
          std::vector<int> combination;
          for (int j=0; j<=idx; ++j)
            for (int k=0; k<x[j]; ++k)
              combination.push_back(candidates[j]);
          combinations.push_back(combination);
          return;
        } else if (s > target)
          return;
        else
          findCombination(candidates, target, x, idx+1, combinations);
      }
    }
};

// Solution 1: From LeetCode Discuss, smarter one.
class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> & candidates, int target) {
      std::vector<std::vector<int> > combinations;
      std::vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSum(combinations, combination, candidates, target, 0);
      return combinations;
    }

  private:
    void combinationSum(std::vector<std::vector<int> > & combinations, std::vector<int> & combination, std::vector<int> & candidates, int target, int idx) {
      if (!target) {
        combinations.push_back(combination);
        return;
      }

      for (size_t i=idx; i<candidates.size()&&target>=candidates[i]; ++i) {
        combination.push_back(candidates[i]);
        combinationSum(combinations, combination, candidates, target-candidates[i], i);
        combination.pop_back();
      }
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input an positive integer array and a target value: ";
  std::vector<int> iv;
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);
  int target = iv[iv.size()-1];
  iv.pop_back();
  std::cout << "Original vector:";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << ' ' << iv[i];
  std::cout << "; Target: " << target;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\t\t=== Solution " << si << " ===" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > combinations = solutions[si]->combinationSum(iv, target);
    std::cout << "The solution sets are: " << std::endl;
    for (size_t i=0; i<combinations.size(); ++i) {
      for (size_t j=0; j<combinations[i].size(); ++j)
        std::cout << ' ' << combinations[i][j];
      std::cout << std::endl;
    }
  }

  return 0;
}
