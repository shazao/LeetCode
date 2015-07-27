/* The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. */

// Star: 7.7.

#include <iostream>
#include <stdlib.h>
#include <sstream>

std::string countAndSay(int n) {

  std::string result("");
  if (n <= 0)
    return result;

  result = "1";
  int len = 1;
  for (int i=1; i<n; ++i) {
    std::stringstream ss;
    size_t j = 0;
    for (; j<result.length()-1; ++j) {
      if (result[j] == result[j+1])
        ++ len;
      else {
        ss << len << result[j];
        len = 1;
      }
    }
    ss <<  len << result[j];
    len = 1;
    result = ss.str();
  }

  return result;
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int i = 1;
  std::string s;
  for (; i<=n; ++i) {
    s = countAndSay(i);
    std::cout << s << std::endl;
  }

  return 0;
}
