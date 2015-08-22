/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

// Star: 7.5.
// Info.: Don't know how to solve it and have no desire to.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::string intToRoman(int num) {
  std::vector<std::string> M({"", "M", "MM", "MMM"});
  std::vector<std::string> C({"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"});
  std::vector<std::string> X({"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"});
  std::vector<std::string> I({"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"});
  return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int n;
  std::string s;

 n = 1900; s = "MCM"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1990; s = "MCMXC"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1991; s = "MCMXCI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1992; s = "MCMXCII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1993; s = "MCMXCIII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1994; s = "MCMXCIV"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1995; s = "MCMXCV"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1996; s = "MCMXCVI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1997; s = "MCMXCVII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1998; s = "MCMXCVIII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1999; s = "MCMXCIX"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2000; s = "MM"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2001; s = "MMI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2002; s = "MMII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2003; s = "MMIII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2004; s = "MMIV"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2005; s = "MMV"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2006; s = "MMVI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2007; s = "MMVII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2008; s = "MMVIII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2009; s = "MMIX"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2010; s = "MMX"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2011; s = "MMXI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2012; s = "MMXII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2013; s = "MMXIII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2014; s = "MMXIV"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2015; s = "MMXV"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2016; s = "MMXVI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2017; s = "MMXVII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2018; s = "MMXVIII"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2019; s = "MMXIX"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 2020; s = "MMXX"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;
 n = 1976; s = "MCMLXXVI"; std::cout << n << " -> " << intToRoman(n) << (intToRoman(n)==s ? "\to" : "\tx") << std::endl;

  return 0;
}
