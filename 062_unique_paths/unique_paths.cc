/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach 

the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
*/

// Star: 8.0.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int uniquePaths(int m, int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Iterative method.
class Solution0 : public Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m<=0 || n<=0) return 0;
      std::vector<std::vector<int> > paths(m, std::vector<int>(n, 1));
      //for (int i=0; i<m; ++i) paths[i][0] = 1;
      //for (int j=0; j<n; ++j) paths[0][j] = 1;
      for (int i=1; i<m; ++i)
        for (int j=1; j<n; ++j)
          paths[i][j] = paths[i][j-1] + paths[i-1][j];

      return paths[m-1][n-1];
    }
};

// Recursive method, surely TLE.
class Solution1 : public Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m+n > 35) {
        std::cout << "The grid is too large for me to solve!" << std::endl;
        return 0;
      }
      if (m==1 || n==1)
        return 1;

      return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};

// Recursive method with memoization.
class Solution2 : public Solution {
  public:
    int uniquePaths(int m, int n) {
      std::vector<std::vector<int> > paths(m, std::vector<int>(n, 0));
      -- m; -- n;
      if (m==0 || n==0)
        return 1;
      return uniquePaths(m-1, n, paths) + uniquePaths(m, n-1, paths);
    }

  private:
    int uniquePaths(int m, int n, std::vector<std::vector<int> > & paths) {
      if (paths[m][n])
        return paths[m][n];
      if (m==0 || n==0)
        return 1;
      paths[m][n] = uniquePaths(m-1, n, paths) + uniquePaths(m, n-1, paths);
      return paths[m][n];
    }
};

// Mathematical method: calculate C(m+n-2, m-1) or C(m+n-2, n-1).
class Solution3 : public Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m<=0 || n<=0)
        return 0;

      int a = m + n - 2;
      int b = m > n ? n - 1 : m - 1;

      //int c = 1;      // Not applicable, just use double.
      //int d = 1;
      //for (int i=1; i<=b; ++i) {
      //  c *= a--;
      //  d *= i;
      //  if (c % d == 0) {
      //    c /= d;
      //    d = 1;
      //  }
      //}
      //return c/d;

      double c = 1.0, d = 1.0;
      for (int i=1; i<=b; ++i) {
        c *= a--;
        d *= i;
      }
      return (int)std::round(c/d);
    }
};

int main(int argc, char * argv[]) {

  if (argc != 3) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  Solution2 s2; solutions.push_back(&s2);
  Solution3 s3; solutions.push_back(&s3);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << solutions[si]->uniquePaths(m, n) << std::endl;
  }

  return 0;
}


// A solution from LeetCode Discuss with optimized space.
/*
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)   // Calculate it column by column.
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 
*/
