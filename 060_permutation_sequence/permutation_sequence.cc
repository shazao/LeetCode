/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

// Star: 8.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::string getPermutation(int n, int k) = 0; // Pure virtual, or Solutionx may not have data members.
};

/* Solution based on backtracking permutation is wrong;
 * The result of backtracking method is not next-permutation order. */
class Solution0 : public Solution {
  public:
    std::string getPermutation(int n, int k) {
      std::string permutation;
      for (size_t i=1; i<=n; ++i)
        permutation.push_back('0'+i);
      int cnt = 0;
      permute(permutation, k, cnt, 0);
      return permutation;
    }

  private:
    void permute(std::string & permutation, int k, int & cnt, int idx) {
      if (idx == permutation.size()) {
        ++ cnt;
        //std::cout << std::endl << ">> " << permutation << std::endl;
        return ;
      }
      for (size_t i=idx; i<permutation.size() && cnt<k; ++i) {
        std::swap(permutation[i], permutation[idx]);
        permute(permutation, k, cnt, idx+1);
        if (cnt < k)
          std::swap(permutation[i], permutation[idx]);
      }
    }
};

// Thought of this solution.
class Solution1 : public Solution {
  public:
    std::string getPermutation(int n, int k) {
      std::string result;
      int factorials[10] = { 0 };
      factorials[0] = 1;
      for (int i=1; i<10; ++i)
        factorials[i] = factorials[i-1] * i;
      std::vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};

      -- k;
      for (int i=n; i>0; --i) {
        int idx = k/factorials[i-1];
        k %= factorials[i-1];
        result.push_back(digits[idx] + '0');
        digits.erase(digits.begin() + idx);
      }
      return result;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int n = 0, k = 0;
  std::cout << "Please input the n: "; std::cin >> n;
  std::cout << std::endl;
  std::cout << "Please input the k: "; std::cin >> k;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The " << k << "th permutation is " <<
      solutions[si]->getPermutation(n, k) << '.' << std::endl << std::endl;
  }

  return 0;
}
