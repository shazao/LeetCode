/* Implement atoi to convert a string to an integer. */

#include <iostream>
#include <limits.h>

// Star: 5.

int myAtoi(std::string str) {

  long sum = 0;
  int sign = 1;
  int j = 0;
  for (; j<str.length(); ++j) {     // Skip leading spaces.
    if (str[j] != ' ')
      break;
  }
  for (int i=j; i<str.length(); ++i) {
    char c = str[i];
    if (i == j) {
      if (c == '-') {
        sign = -1;
        continue;
      }
      else if (c == '+') {
        sign = 1;
        continue;
      }
    }
    if (!(c>='0' && c<='9'))
      return sign*sum;      // Do not return 0, return you've got so far.
    sum = sum*10 + c - '0';
    /* Another good way to handle overflow.
     * If the current number is greater than 214748364, we know it is going to overflow. 
     * On the other hand, if the current number is equal to 214748364, 
     * we know that it will overflow only when the current digit is greater than or equal to 8. */
    if (sign==1 && sum>INT_MAX)
      return INT_MAX;
    if (sign==-1 && sum>(unsigned int)INT_MAX+1) 
      return INT_MIN;
  }
  return sign*sum;
}

int main() {

  std::string s = "  12";
  std::cout << s << std::endl << myAtoi(s) << std::endl;

  s = "  -123456";
  std::cout << s << std::endl << myAtoi(s) << std::endl;

  s = " +654321";
  std::cout << s << std::endl << myAtoi(s) << std::endl;

  s = "6543216543";
  std::cout << s << std::endl << myAtoi(s) << std::endl;

  s = "-2147483648";
  std::cout << s << std::endl << myAtoi(s) << std::endl;

  s = "-2147483649";
  std::cout << s << std::endl << myAtoi(s) << std::endl;

  return 0;
}
