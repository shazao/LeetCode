/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C 

where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

// Star: 8.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > combinationSum2(std::vector<int> & candidates, int target) = 0;
};

// Solution 0: My method, dealing with duplicate using unordered_set is time exhausting; So only beats 8.26% of C++ submissions.
class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> & candidates, int target) {
      std::vector<std::vector<int> > combinations;
      sort(candidates.begin(), candidates.end());
      std::vector<int> x(candidates.size(), 0);

      findCombination(candidates, target, x, 0, combinations);

      return combinations;
    }

  private:
    std::unordered_set<std::string> combination_set_;

    std::string to_string(int i) {
      std::string str;
      if (i < 0) {
        i = -i;
        str.push_back('-');
      }
      while (i) {
        str.push_back(i%10 + '0');
        i /= 10;
      }
      if (str[0] == '-')
        reverse(str.begin()+1, str.end());
      else
        reverse(str.begin(), str.end());
      return str;
    }

    void findCombination(std::vector<int> & candidates, int target, std::vector<int> & x, int idx, std::vector<std::vector<int> > & combinations) {
      if (idx == candidates.size())
        return;

      for (int i=0; i<=1; ++i) {
        x[idx] = i;
        target -= i*candidates[idx];
        if (!target) {
          std::vector<int> combination;
          std::string id;
          for (int j=0; j<=idx; ++j)
            if (x[j]) {
              combination.push_back(candidates[j]);
              id += to_string(candidates[j]);   // Time exhausting.
            }
          if (combination_set_.find(id) == combination_set_.end()) {
            combinations.push_back(combination);
            combination_set_.insert(id);
          }
          return;
        } else if (target > 0) {
          findCombination(candidates, target, x, idx+1, combinations);
          target += i*candidates[idx];
        } else
          return;
      }
    }
};

// Solution 1: Search from another dimension. From LeetCode Discuss.
class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> & candidates, int target) {
      std::vector<std::vector<int> > combinations;
      std::vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSum2(candidates, target, combinations, combination, 0);
      return combinations;
    };
  private:
    void combinationSum2(std::vector<int> & candidates, int target, std::vector<std::vector<int> > & combinations, std::vector<int> & combination, int idx) {
      if (!target) {
        combinations.push_back(combination);
        return ;
      }
      for (size_t i=idx; i<candidates.size()&&target>=candidates[i]; ++i) {
        if (i==idx || candidates[i]!=candidates[i-1]) {
          combination.push_back(candidates[i]);
          combinationSum2(candidates, target-candidates[i], combinations, combination, i+1);
          combination.pop_back();
        }
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
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > combinations = solutions[si]->combinationSum2(iv, target);
    std::cout << "The solution sets are: " << std::endl;
    for (size_t i=0; i<combinations.size(); ++i) {
      for (size_t j=0; j<combinations[i].size(); ++j)
        std::cout << ' ' << combinations[i][j];
      std::cout << std::endl;
    }
  }

  return 0;
}
