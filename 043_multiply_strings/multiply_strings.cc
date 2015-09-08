/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

// Star: 8.5.
// Info.: Do not how to solve it elegantly.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// From LeetCode Discuss, smart. And makes it an interesting problem.
std::string multiply(std::string num1, std::string num2) {
  int n1 = num1.size(), n2 = num2.size();
  std::string product(n1+n2, '0');
  for (int i=n1-1; i>=0; --i) {
    int sum = 0;
    for (int j=n2-1; j>=0; --j) {
      sum = product[i+j+1]-'0' + (num1[i]-'0')*(num2[j]-'0') + sum/10;
      product[i+j+1] = sum%10 + '0';
    }
    product[i] = sum/10 + '0';
  }

  size_t pos_vld = product.find_first_not_of('0');
  if (pos_vld != std::string::npos) {
    product.erase(product.begin(), product.begin()+pos_vld);
    return product;
  }
  return "0";
}

int main(int argc, char * argv[]) {

  if (argc != 3) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::string s1(argv[1]);
  std::string s2(argv[2]);
  std::cout << s1 << " x " << s2 << " = " << multiply(s1, s2) << std::endl;

  return 0;
}
