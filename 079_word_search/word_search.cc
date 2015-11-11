/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 

where "adjacent" cells are those horizontally or vertically neighboring. 

The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual bool exist(std::vector<std::vector<char> > & board, std::string word) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My solution; Completed it quite hard, and performance not good.
class Solution0 : public Solution {
  public:
    bool exist(std::vector<std::vector<char> > & board, std::string word) {
      if (word.empty()) return true;
      std::vector<std::vector<int> > flag(board.size(), std::vector<int>(board[0].size(), 0));
      for (int i=0; i<board.size(); ++i)
        for (int j=0; j<board[i].size(); ++j)
          if (board[i][j] == word[0])
            if (exist(board, word, flag, i, j, 0))
              return true;
            else
              flag = std::vector<std::vector<int> >(board.size(), std::vector<int>(board[0].size(), 0));
      return false;
    }

  private:
    const int di_[4] = {0, 1, 0, -1};
    const int dj_[4] = {-1, 0, 1, 0};

    bool exist(std::vector<std::vector<char> > & board, std::string & word, std::vector<std::vector<int> > & flag, int i, int j, int k) {
      if (board[i][j] != word[k]) {
        flag[i][j] = 0;
        return false;
      }
      flag[i][j] = 1;   // Must be put below the line above.
      if (k == word.size()-1) return true;

      int n_directions = sizeof(di_)/sizeof(di_[0]);
      bool exist_remained = false;
      for (int l=0; l<n_directions; ++l) {
        int i_ = i + di_[l];
        int j_ = j + dj_[l];
        if (i_<0 || i_>=board.size() || j_<0 || j_>=board[0].size() || flag[i_][j_]==1)
          continue;
        if (exist(board, word, flag, i_, j_, k+1))
          exist_remained = true;
      }
      if (exist_remained) return true;
      else {
        flag[i][j] = 0;   // Reset the flag before return false!
        return false;
      }
    }
};

class Solution1 : public Solution {
  public:
    bool exist(std::vector<std::vector<char> > & board, std::string word) {
      if (word.empty()) return true;
      if (board.empty()) return false;
      m_ = board.size(); n_ = board[0].size();
      for (int i=0; i<m_; ++i)
        for (int j=0; j<n_; ++j)
          if (exist(board, word, i, j, 0))
            return true;
      return false;
    }
  
  private:
    int m_;
    int n_;

    bool exist(std::vector<std::vector<char> > & board, std::string & word, int i, int j, int k) {
      if (i<0 || i>=m_ || j<0 || j>=n_ || board[i][j]=='\0')
        return false;
      if (board[i][j] != word[k])
        return false;
      char tmp = board[i][j];
      board[i][j] = '\0';
      if (k == word.size()-1 ||
          exist(board, word, i, j-1, k+1) ||
          exist(board, word, i+1, j, k+1) ||
          exist(board, word, i, j+1, k+1) ||
          exist(board, word, i-1, j, k+1))
        return true;
      else {
        board[i][j] = tmp;
        return false;
      }
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get a matrix; Ctrl+Z or Ctrl+D to stop.
  std::vector<std::vector<char> > matrix;
  std::cout << "Please input a character matrix: " << std::endl;
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
      return -1;
    } else
      matrix.push_back(row);
  }
  std::cout << "\nThe matrix you gave is: " << std::endl;
  for (size_t i=0; i<matrix.size(); ++i) {
    for (size_t j=0; j<matrix[i].size(); ++j)
      std::cout << ' ' << matrix[i][j];
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::cin.clear();
  std::cin.sync();

  std::cout << "Please input the word: ";
  std::string line;
  std::getline(std::cin, line);
  std::cout << "The word you input is: \"" << line << "\"" << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The matrix above does " << (solutions[si]->exist(matrix, line)?"exist":"not exist") 
      << " \"" << line << "\"." << std::endl << std::endl;
  }

  return 0;
}
