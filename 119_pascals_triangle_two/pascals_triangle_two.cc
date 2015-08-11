/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

// Star: 7.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Solution 0: A straightforward method, but "long double" looks not so nice.
//int cnm(int n, int m) {
//  if (n<0 || m<0 || m>n)
//    return 0;
//
//  long double sum = 1;
//  long double divider = 1;
//  for (int i=m; i>=1; --i) {
//    // Note 0: "sum /= m--" is wrong!
//    //divider *= m--;
//    //if (sum%divider == 0) {   // Note 1: In case of overflowing of sum.
//    //  sum /= divider;
//    //  divider = 1;
//    //}
//    //sum *= n--;
//    sum *= n--;
//    divider *= m--;
//  }
//
//  return sum/divider;
//}
//
//std::vector<int> getRow(int rowIndex) {
//  std::vector<int> rtn;
//  if (rowIndex < 0)
//    return rtn;
//
//  int i = 0;
//  for (; i<=rowIndex/2; ++i)
//    rtn.push_back(cnm(rowIndex, i));
//  for (; i<rowIndex+1; ++i)
//    rtn.push_back(rtn[rowIndex-i]);
//
//  return rtn;
//}

// Solution 1: A smarter method, realizing in-place.
std::vector<int> getRow(int rowIndex) {
  std::vector<int> rtn;
  if (rowIndex < 0)
    return rtn;

  rtn.resize(rowIndex+1);
  rtn[0] = 1;
  for (int i=1; i<=rowIndex; ++i)
    for (int j=i; j>=0; --j)
      if (j==i || j==0)
        rtn[j] = 1;
      else
        rtn[j] = rtn[j] + rtn[j-1];

  return rtn;
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  for (int i=0; i<=std::atoi(argv[1]); ++i) {
    std::vector<int> row = getRow(i);
    for (int j=0; j<row.size(); ++j)
      std::cout << row[j] << " ";
    std::cout << std::endl;
  }

  return 0;
}
