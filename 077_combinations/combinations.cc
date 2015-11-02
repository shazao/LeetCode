/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// Star: 9.3.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<int> > combine(int n, int k) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<std::vector<int> > combine(int n, int k) {
      if (n<k || k<=0) return combinations_;
      combine(1, n, k);
      return combinations_;
    }
    
  private:
    std::vector<std::vector<int> > combinations_;
    std::vector<int> combination_;

    void combine(int start, int n, int k) {
      if (combination_.size() == k) {
        combinations_.push_back(combination_);
        return ;
      }
      for (size_t i=start; i<=n; ++i) {
        combination_.push_back(i);
        combine(i+1, n, k);
        combination_.pop_back();
      }
    }
};

/* From LeetCode Discuss: First, choose a number and push_back; 
 * Second, choose a larger number; Until k number chose. */
class Solution1 : public Solution {
  public:
    std::vector<std::vector<int> > combine(int n, int k) {
      if (n<k || k<=0) return combinations_;
      combination_.resize(k);
      combine(1, n, k);
      return combinations_;
    }
    
  private:
    std::vector<std::vector<int> > combinations_;
    std::vector<int> combination_;

    void combine(int start, int n, int k) {
      while (start <= n) {
        combination_[combination_.size() - k] = start++;
        if (k > 1)
          combine(start, n, k-1);
        else
          combinations_.push_back(combination_);
      }
    }
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the n and the k: ";
  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<int> > combinations = solutions[si]->combine(n, k);
    std::cout << "The " << combinations.size() << " combinations are: " << std::endl;
    for (size_t i=0; i<combinations.size(); ++i) {
      for (size_t j=0; j<combinations[i].size(); ++j)
        std::cout << ' ' << combinations[i][j];
      std::cout << std::endl << std::endl;
    }
  }

  return 0;
}
