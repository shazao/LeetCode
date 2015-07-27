/* Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] */

#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<std::vector<int> > generate(int numRows) {
  std::vector<std::vector<int> > rtn;
  if (numRows <= 0)
    return rtn;

  std::vector<int> row = { 1 };
  rtn.push_back(row);
  row.clear();
  for (int i=1; i<numRows; ++i) {
    for (int j=0; j<i+1; ++j) {
      int element = 0;
      if (j==0 || j==i)
        element = 1;
      else
        element = rtn[i-1][j-1] + rtn[i-1][j];
      row.push_back(element);
    }
    rtn.push_back(row);
    row.clear();
  }

  return rtn;
}      

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return 0;
  }

  std::vector<std::vector<int> > pt = generate(std::atoi(argv[1]));
  for (size_t i=0; i<pt.size(); ++i) {
    for (size_t j=0; j<pt[i].size(); ++j)
      std::cout << pt[i][j] << " " ;
    std::cout << std::endl;
  }

  return 0;
}
