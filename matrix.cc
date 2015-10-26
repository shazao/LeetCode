#include <iostream>
#include <vector>
#include <sstream>

void getMatrix0() {
  std::vector<std::vector<int> > matrix;
  std::cout << "Please input a matrix: " << std::endl;
  int i = 0;
  while (! std::cin.eof()) {
    std::vector<int> row;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> i)
      row.push_back(i);
    if (row.empty())
      break;
    if (matrix.size()!=0 && row.size()!=matrix[matrix.size()-1].size()) {
      std::cout << "Distorted matrix!" << std::endl;
      return ;
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
}

int main() {
  getMatrix0();
}

/* 
{
  std::vector<std::vector<int> > matrix;
  std::cout << "Please input a matrix: " << std::endl;
  int i = 0;
  while (! std::cin.eof()) {
    std::vector<int> row;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> i)
      row.push_back(i);
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
}
*/
