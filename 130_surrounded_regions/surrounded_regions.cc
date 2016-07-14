/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_set>
#include <queue>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual void solve(std::vector<std::vector<char> > & board) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My initial solution, which is OK I think, but Memory Limit Exceeded.
class Solution0 : public Solution {
  public:
    void solve(std::vector<std::vector<char> > & board) {
      size_t m = board.size();
      if (m == 0) return;
      size_t n = board[0].size();
      if (n == 0) return;
      for (size_t i = 1; i < m-1; ++i)
        for (size_t j = 1; j < n-1; ++j) {
          if (board[i][j] == 'O' && visited_.find(i*n + j)==visited_.end()) {
            std::queue<std::pair<size_t, size_t> > q; q.push(std::make_pair(i, j));
            bool region = true;
            while (!q.empty()) {
              size_t x = q.front().first, y = q.front().second;
              visited_.insert(x*n + y);
              x_.push_back(x); y_.push_back(y);
              q.pop();
              if (x==0 || x==m-1 || y == 0 || y == n-1) { region = false; continue; }
              if (board[x][y-1] == 'O' && visited_.find(x*n + y - 1)==visited_.end()) q.push(std::make_pair(x, y-1));
              if (board[x+1][y] == 'O' && visited_.find((x+1)*n + y)==visited_.end()) q.push(std::make_pair(x+1, y));
              if (board[x][y+1] == 'O' && visited_.find(x*n + y + 1)==visited_.end()) q.push(std::make_pair(x, y+1));
              if (board[x-1][y] == 'O' && visited_.find((x-1)*n + y)==visited_.end()) q.push(std::make_pair(x-1, y));
            }
            if (region)
              for (size_t i=0; i<x_.size(); ++i) {
                std::cout << "Changed " << x_[i] << ", " << y_[i] << "(" << board[x_[i]][y_[i]] << ") ";
                board[x_[i]][y_[i]] = 'X';
                std::cout << "into " << board[x_[i]][y_[i]] << "." << std::endl;
              }
            x_.clear(); y_.clear();
          }
        }
    }
  private:
    std::unordered_set<int> visited_;
    std::vector<int> x_, y_;
};

// My second solution with space optimization, but only beats 3.39%.
class Solution1 : public Solution {
  public:
    void solve(std::vector<std::vector<char> > & board) {
      size_t m = board.size();
      if (m == 0) return;
      size_t n = board[0].size();
      if (n == 0) return;
      std::vector<size_t> border_o_idx;
      for (size_t j=0; j<n; ++j) if (board[0][j] == 'O') border_o_idx.push_back(j);
      for (size_t j=0; j<n; ++j) if (board[m-1][j] == 'O') border_o_idx.push_back((m-1)*n + j);
      for (size_t i=1; i<m-1; ++i) if (board[i][0] == 'O') border_o_idx.push_back(i*n);
      for (size_t i=1; i<m-1; ++i) if (board[i][n-1] == 'O') border_o_idx.push_back(i*n + n - 1);
      std::unordered_set<size_t> unsurrounded_idx;
      std::unordered_set<size_t> visited;
      for (size_t i=0; i<border_o_idx.size(); ++i) {
        std::queue<size_t> q; q.push(border_o_idx[i]);
        while (!q.empty()) {
          size_t x = q.front() / n, y = q.front() % n;
          unsurrounded_idx.insert(q.front());
          if (visited.find(q.front()) == visited.end()) {
            visited.insert(q.front());
            if (y > 0 && board[x][y-1] == 'O') q.push(x*n + y - 1);
            if (x < m - 1 && board[x+1][y] == 'O') q.push((x+1)*n + y);
            if (y < n - 1 && board[x][y+1] == 'O') q.push(x*n + y + 1);
            if (x > 0 && board[x-1][y] == 'O') q.push((x-1)*n + y);
          }
          q.pop();
        }
      }
      for (size_t i=1; i<m-1; ++i)
        for (size_t j=1; j<n-1; ++j)
          if (board[i][j] == 'O' && unsurrounded_idx.find(i*n + j)==unsurrounded_idx.end())
            board[i][j] = 'X';
      return;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get a matrix; Ctrl+Z or Ctrl+D to stop.
  std::vector<std::vector<char> > matrix;
  std::cout << "Please input a matrix: " << std::endl;
  char c = 0;
  while (! std::cin.eof()) {
    std::vector<char> row;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> c)
      row.push_back(c);
    if (row.empty())
      break;
    if (matrix.size()!=0 && row.size()!=matrix[matrix.size()-1].size()) {
      std::cout << "Distorted matrix!" << std::endl;
      exit(1);
    } else
      matrix.push_back(row);
  }
  std::cout << "\nThe matrix you gave is: " << std::endl;
  std::vector<std::vector<char> > original_matrix(matrix.size(), std::vector<char>());
  for (size_t i=0; i<matrix.size(); ++i) {
    for (size_t j=0; j<matrix[i].size(); ++j) {
      std::cout << ' ' << matrix[i][j];
      original_matrix[i].push_back(matrix[i][j]);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    for (size_t i=0; i<matrix.size(); ++i)
      for (size_t j=0; j<matrix[i].size(); ++j)
        matrix[i][j] = original_matrix[i][j];
    Profiler perf;
    solutions[si]->solve(matrix);
    std::cout << "\nThe processed matrix now is: " << std::endl;
    for (size_t i=0; i<matrix.size(); ++i) {
      for (size_t j=0; j<matrix[i].size(); ++j)
        std::cout << ' ' << matrix[i][j];
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
