/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

// Star: 7.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

std::string convertToTitle(int n) {
  std::string rtn;
  if (n <= 0)
    return rtn;

  while (n) {
    int m = n%26;
    if (m == 0) {
      m = 26;
      n -= 26;
    }
    rtn.push_back(m + 'A' - 1);
    n /= 26;
  }

  //size_t len = rtn.length();
  //std::string reversed(len, 'x');
  //for (size_t i=0; i<len; ++i)
  //  reversed[i] = rtn[len-i-1];
  //return reversed;

  if (rtn.length() > 1)
    reverse(rtn.begin(), rtn.end());

  return rtn;
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  for (int i=1; i<=std::atoi(argv[1]); ++i)
    std::cout << i << " -> " << convertToTitle(i) << std::endl;

  return 0;
}

// Seems a better one.
//char* convertToTitle(int n) {
//    char *res = (char *)calloc(8, sizeof(char));
//    int i = 6;
//    while(n){
//        res[i--] = (char)((n-1) % 26) + 'A';
//        n = (n - 1) / 26;
//    }
//    return res+i+1;
//}
