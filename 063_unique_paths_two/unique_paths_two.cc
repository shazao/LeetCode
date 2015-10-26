/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

// Star: 8.5.
// Info.: Note that there is not only one obstacle.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int uniquePathsWithObstacles(std::vector<std::vector<int> > & obstacleGrid) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Wrong solution, just handled cases those have only one obstacle.
class Solution0 : public Solution {
  public:
    int uniquePathsWithObstacles(std::vector<std::vector<int> > & obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (obstacleGrid[i][j])
            if ((i==0 && j==0) || (i==m-1&&j==n-1))
              return 0;
            else
              return uniquePaths(m, n) - uniquePaths(i+1, j+1) * uniquePaths(m-i, n-j);
      return 0;
    }
  
  private:
    int uniquePaths(int m, int n) {
      if (m<=0 || n<=0) return 0;
      std::vector<int> column(m, 1);
      for (int i=1; i<n; ++i)
        for (int j=1; j<m; ++j)
          column[j] += column[j-1];

      return column[m-1];
    }
};

class Solution1 : public Solution {
  public:
    int uniquePathsWithObstacles(std::vector<std::vector<int> > & obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      std::vector<std::vector<int> > paths(m+1, std::vector<int>(n+1, 0));
      paths[0][1] = 1;    // Note!
      for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j)
          if (!obstacleGrid[i-1][j-1])
            paths[i][j] = paths[i][j-1] + paths[i-1][j];
      return paths[m][n];
    }
};

int main(int argc, char * argv[]) {

  if (argc != 5) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  int i = atoi(argv[3]);
  int j = atoi(argv[4]);
  std::vector<std::vector<int> > obstacleGrid(m, std::vector<int>(n, 0));
  obstacleGrid[i-1][j-1] = 1;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << solutions[si]->uniquePathsWithObstacles(obstacleGrid) << std::endl << std::endl;
  }

  return 0;
}
