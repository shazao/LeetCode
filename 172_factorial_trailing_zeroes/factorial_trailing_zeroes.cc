/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

// Star: 7.
// Info.: Method 2.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Solution 0: Not so efficient.
//int trailingZeroes(int n) {
//  if (n <= 0)
//    return 0;
//
//  int rtn = 0;
//  for (int i=1; i<=n; ++i) {
//    int ii = i;
//    if (ii%5 == 0) {
//      ++ rtn;
//      ii /= 5;
//      while (ii%5 == 0) {
//        ++ rtn;
//        ii /= 5;
//      }
//    }
//  }
//
//  return rtn;
//}

// Solution 1.
int trailingZeroes(int n) {
  if (n <= 0)
    return 0;

  int rtn = 0;
  while (n) {
    rtn += n/5;
    n /= 5;
  }

  return rtn;
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int n = std::atoi(argv[1]);
  std::cout << n << "! has " << trailingZeroes(n) << " trailing zeroes." << std::endl;

  return 0;
}
