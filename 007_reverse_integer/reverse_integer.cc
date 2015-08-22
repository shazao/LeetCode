/* Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 */
#include <iostream>
#include <limits.h>

// Star: 6.5.

// Solution 0;
//int reverse(int x) {
//
//  int y = x>0 ? x : -x;   // Cannot handle INT_MIN. (INT_MAX+1 == INT_MIN)
//  //std::cout << y << std::endl;
//
//  int m = y % 10;
//  int s = 0;
//  int s_ = s;
//  while (y) {
//    s_ = s;
//    s = s*10 + m;
//    y /= 10;
//    m = y % 10;
//    if (s < s_) 
//      return 0;
//  }
//
//  return x>0 ? s : -s;
//}

// Solution 1.
//int reverse(int x) {
//
//   unsigned int y = x>0 ? x : -x;
//   int m = y % 10;
//   unsigned int s = 0;      // "unsigned int" is not big enough.
//   while (y) {
//     s = s*10 + m;
//     if (x > 0) 
//       if (s > INT_MAX)
//         return 0;
//     if (x < 0)
//       if (s > (unsigned int)INT_MAX+1)
//         return 0;
//     y /= 10;
//     m = y % 10;
//   }
//
//   return x>0 ? s : -s;
//}

// Solution 2(It's also not so good I think.).
int reverse(int x) {

   unsigned int y = x>0 ? x : -x;
   int m = y % 10;
   unsigned long s = 0;
   while (y) {
     s = s*10 + m;
     if (x > 0) 
       if (s > INT_MAX)
         return 0;
     if (x < 0)
       if (s > (unsigned int)INT_MAX+1)   // Note the conversion.
         return 0;
     y /= 10;
     m = y % 10;
   }

   return x>0 ? s : -s;
}

/* To check for overflow/underflow, we could check if ret > 214748364 or ret < -214748364 before multiplying by 10. 
 * On the other hand, we do not need to check if ret == 214748364, why? */

int main() {

  //std::cout << (unsigned int)INT_MAX+1 << std::endl;

  int x = -1234;
  std::cout << x << std::endl;
  std::cout << reverse(x) << std::endl << std::endl;

  x = -100;
  std::cout << x << std::endl;
  std::cout << reverse(x) << std::endl << std::endl;

  // Cannot pass solution 0(s: 0011 1110..., s_: 0011 1001...).
  // Cannot pass solution 1(unsigned int is also not big enough).
  x = 1534236469;
  std::cout << x << std::endl;
  std::cout << reverse(x) << std::endl << std::endl;

  x = INT_MAX;
  std::cout << x << std::endl;
  std::cout << reverse(x) << std::endl << std::endl;

  x = INT_MIN;
  std::cout << x << std::endl;
  std::cout << reverse(x) << std::endl;

  return 0;
}
