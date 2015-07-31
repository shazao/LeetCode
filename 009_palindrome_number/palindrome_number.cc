/* Determine whether an integer is a palindrome. Do this without extra space. */
#include <iostream>
#include <cmath>

// Star: 7.

// Solution 0: Not so efficient.
//bool isPalindrome(int x) {
//
//  if (x < 0) 
//    return false;
//
//  int y = x;
//  int w = 0;
//  while (y) {
//    ++ w;
//    y /= 10;
//  }
//  
//  -- w;
//
//  while (x) {
//    int h = x / std::pow(10, w);
//    int l = x % 10;
//    if (h != l)
//      return false;
//    x -= h * std::pow(10, w);
//    x /= 10;
//    w -= 2;
//  }
//
//  return true;
//}

// Solution 1.
bool isPalindrome(int x) {

  if (x < 0) 
    return false;

  int y = x;
  int w = 1;
  while (y /= 10)
    w *= 10;

  while (x) {
    int h = x / w;
    int l = x % 10;
    if (h != l)
      return false;
    x -= h * w;
    x /= 10;
    w /= 100;
  }

  return true;
}

int main() {
  int i = 12321;
  std::cout << i << (isPalindrome(i) ? " is " : " is not ") << "palindrome number." << std::endl;
  
  i = 3;
  std::cout << i << (isPalindrome(i) ? " is " : " is not ") << "palindrome number." << std::endl;
  
  i = 0;
  std::cout << i << (isPalindrome(i) ? " is " : " is not ") << "palindrome number." << std::endl;
  
  i = -12321;
  std::cout << i << (isPalindrome(i) ? " is " : " is not ") << "palindrome number." << std::endl;
  
  i = 123321;
  std::cout << i << (isPalindrome(i) ? " is " : " is not ") << "palindrome number." << std::endl;
  
  return 0;
}
