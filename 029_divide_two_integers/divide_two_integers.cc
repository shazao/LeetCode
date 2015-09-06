/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

// Star: 8.2.
// Info.: Worth trying again.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <climits>

// Solution 0: My method, but MLE(Memory Limit Exceeded).
//int divide(int dividend, int divisor) {
//  int result = 0;
//  if (divisor == 0) 
//    return INT_MAX;
//  bool positive = true;
//  if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
//    positive = false;
//  dividend = dividend>0?dividend:-dividend;
//  divisor = divisor>0?divisor:-divisor;
//
//  std::vector<int> multiples;
//  while (divisor <= dividend) {
//    multiples.push_back(divisor);
//    if ((unsigned int)divisor + (unsigned int)divisor > (unsigned int)INT_MAX)  // Every conversion is a must.
//      break;
//    divisor += divisor;
//  }
//  for (int i=multiples.size()-1; i>=0; --i)
//    if (multiples[i] <= dividend) {
//      dividend -= multiples[i];
//      result += 0x01<<i;
//      if (dividend==0)
//        break;
//    }
//  return positive?result:-result;
//}

// Solution 1: Don't store the divisor*2^power, but still many flaws.
//int divide(int dividend, int divisor) {
//  int result = 0;
//  if (divisor == 0) 
//    return INT_MAX;
//  bool positive = true;
//  if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
//    positive = false;
//  unsigned int dividend_ui = dividend>0?dividend:-dividend;   // Note 1: The conversion from INT_MIN to INT_MAX will overflow.
//  unsigned int divisor_ui = divisor>0?divisor:-divisor;
//
//  // Got the power so that divisor*2^power <= dividend.
//  int power = -1;
//  int d = divisor_ui;
//  while (d <= dividend_ui) {
//    ++ power;
//    if ((unsigned int)d + (unsigned int)d > (unsigned int)INT_MAX)  // Note 0: Every conversion is a must.
//      break;
//    d += d;   // Note 2: -INT_MIN - INT_MIN overflows!
//  }
//  for (int i=power; i>=0; --i) {
//    int multiple = divisor_ui<<i;
//    if (multiple <= dividend_ui) {
//      dividend_ui -= multiple;
//      result += 0x01<<i;
//      if (dividend_ui==0)
//        break;
//    }
//  }
//  return positive?result:-result;
//}

// Solution 2: Use long long!
// Info.: For integer literals, u, U --> unsigned; l, L --> long; ll, LL --> long long. 
//        For floating-point literals, f, F --> float; l, L --> long double.
int divide(int dividend, int divisor) {
  long long result = 0;
  long long dvdd = dividend;
  long long dvsr = divisor;
  if (dvsr == 0) 
    return INT_MAX;
  bool positive = true;
  if ((dvdd>0 && dvsr<0) || (dvdd<0 && dvsr>0))
    positive = false;
  dvdd  = dvdd>0?dvdd:-dvdd;
  dvsr = dvsr>0?dvsr:-dvsr;

  // Got the power so that divisor*2^power <= dividend.
  int power = -1;
  long long d = dvsr;
  while (d <= dvdd) {
    ++ power;
    d += d;
  }
  for (int i=power; i>=0; --i) {
    long long multiple = dvsr<<i;
    if (multiple <= dvdd) {
      dvdd -= multiple;
      result += 0x01LL<<i;    // Note 0: "LL"!  
      if (dvdd == 0)
        break;
    }
  }
  result = positive?result:-result;
  if (result > INT_MAX)     // Note 1: May overflow.
    return INT_MAX;
  return result;
}

int main(int argc, char * argv[]) {

  if (argc != 3) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int dividend = atoi(argv[1]);
  int divisor = atoi(argv[2]);
  int result = divide(dividend, divisor);

  std::cout << dividend << " divided by " << divisor << " is: " << result;
  // The following line does not work with INT_MIN/-1.
  std::cout << "(The correct answer is " << dividend/divisor << ")." << std::endl;

  for (int i=63; i<=129; ++i)
    for (int j=10; j<=65; ++j) {
      int my_result = divide(i, j);
      std::cout << i << '/' << j << " = " << my_result << "\t(" << (my_result==i/j?'O':'X') << ')' << std::endl;
    }

  dividend = INT_MAX;
  divisor = INT_MAX-1;
  result = divide(dividend, divisor);
  std::cout << dividend << " divided by " << divisor << " is: " << result << "(The correct answer is " << dividend/divisor << ")." << std::endl;

  dividend = INT_MAX;
  divisor = INT_MAX/2;
  result = divide(dividend, divisor);
  std::cout << dividend << " divided by " << divisor << " is: " << result << "(The correct answer is " << dividend/divisor << ")." << std::endl;

  dividend = INT_MAX;
  divisor = 10;
  result = divide(dividend, divisor);
  std::cout << dividend << " divided by " << divisor << " is: " << result << "(The correct answer is " << dividend/divisor << ")." << std::endl;

  return 0;
}
