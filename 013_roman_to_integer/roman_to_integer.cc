/* Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999. */
#include <iostream>
#include <string>
#include <map>

// Star: 6.5.

// Solution 0: Not so efficient.
//int rtoi(char c) {
//  switch (c) {
//    case 'I': return 1;
//    case 'V': return 5;
//    case 'X': return 10;
//    case 'L': return 50;
//    case 'C': return 100;
//    case 'D': return 500;
//    case 'M': return 1000;
//    default : return 0;
//  }
//}
//
//int romanToInt(std::string s) {
//
//  int sum = 0;
//  for (int i=0; i<s.length(); ++i) {
//    char c = s[i];
//    char d = s[i+1];
//
//    if (c == 'I' || c == 'X' || c == 'C') {
//      if (rtoi(d) > rtoi(c)) {
//        sum += rtoi(d) - rtoi(c);
//        ++ i;
//      } else 
//        sum += rtoi(c);
//    } else 
//      sum += rtoi(c);
//  }
//
//  return sum;
//}

// Solution 1.
static std::map<char, int> ri_map ({
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
  });


int romanToInt(std::string s) {

  int sum = 0;
  for (int i=0; i<s.length(); ++i) {
    char c = s[i];
    char d = s[i+1];

    if (c == 'I' || c == 'X' || c == 'C') {
      if (ri_map[d] > ri_map[c]) {
        sum += ri_map[d] - ri_map[c];
        ++ i;
      } else 
        sum += ri_map[c];
    } else 
      sum += ri_map[c];
  }

  return sum;
}

int main() {

  std::cout << "Roman numeral | integer\t" << std::endl;

  std::string s;
  s = "MCM"; std::cout << "MCM\t" << romanToInt(s) << (romanToInt(s)==1900 ? "\to" : "\tx") << std::endl;
  s = "MCMXC"; std::cout << "MCMXC\t" << romanToInt(s) << (romanToInt(s)==1990 ? "\to" : "\tx") << std::endl;
  s = "MCMXCI"; std::cout << "MCMXCI\t" << romanToInt(s) << (romanToInt(s)==1991 ? "\to" : "\tx") << std::endl;
  s = "MCMXCII"; std::cout << "MCMXCII\t" << romanToInt(s) << (romanToInt(s)==1992 ? "\to" : "\tx") << std::endl;
  s = "MCMXCIII"; std::cout << "MCMXCIII\t" << romanToInt(s) << (romanToInt(s)==1993 ? "\to" : "\tx") << std::endl;
  s = "MCMXCIV"; std::cout << "MCMXCIV\t" << romanToInt(s) << (romanToInt(s)==1994 ? "\to" : "\tx") << std::endl;
  s = "MCMXCV"; std::cout << "MCMXCV\t" << romanToInt(s) << (romanToInt(s)==1995 ? "\to" : "\tx") << std::endl;
  s = "MCMXCVI"; std::cout << "MCMXCVI\t" << romanToInt(s) << (romanToInt(s)==1996 ? "\to" : "\tx") << std::endl;
  s = "MCMXCVII"; std::cout << "MCMXCVII\t" << romanToInt(s) << (romanToInt(s)==1997 ? "\to" : "\tx") << std::endl;
  s = "MCMXCVIII"; std::cout << "MCMXCVIII\t" << romanToInt(s) << (romanToInt(s)==1998 ? "\to" : "\tx") << std::endl;
  s = "MCMXCIX"; std::cout << "MCMXCIX\t" << romanToInt(s) << (romanToInt(s)==1999 ? "\to" : "\tx") << std::endl;
  s = "MM"; std::cout << "MM\t" << romanToInt(s) << (romanToInt(s)==2000 ? "\to" : "\tx") << std::endl;
  s = "MMI"; std::cout << "MMI\t" << romanToInt(s) << (romanToInt(s)==2001 ? "\to" : "\tx") << std::endl;
  s = "MMII"; std::cout << "MMII\t" << romanToInt(s) << (romanToInt(s)==2002 ? "\to" : "\tx") << std::endl;
  s = "MMIII"; std::cout << "MMIII\t" << romanToInt(s) << (romanToInt(s)==2003 ? "\to" : "\tx") << std::endl;
  s = "MMIV"; std::cout << "MMIV\t" << romanToInt(s) << (romanToInt(s)==2004 ? "\to" : "\tx") << std::endl;
  s = "MMV"; std::cout << "MMV\t" << romanToInt(s) << (romanToInt(s)==2005 ? "\to" : "\tx") << std::endl;
  s = "MMVI"; std::cout << "MMVI\t" << romanToInt(s) << (romanToInt(s)==2006 ? "\to" : "\tx") << std::endl;
  s = "MMVII"; std::cout << "MMVII\t" << romanToInt(s) << (romanToInt(s)==2007 ? "\to" : "\tx") << std::endl;
  s = "MMVIII"; std::cout << "MMVIII\t" << romanToInt(s) << (romanToInt(s)==2008 ? "\to" : "\tx") << std::endl;
  s = "MMIX"; std::cout << "MMIX\t" << romanToInt(s) << (romanToInt(s)==2009 ? "\to" : "\tx") << std::endl;
  s = "MMX"; std::cout << "MMX\t" << romanToInt(s) << (romanToInt(s)==2010 ? "\to" : "\tx") << std::endl;
  s = "MMXI"; std::cout << "MMXI\t" << romanToInt(s) << (romanToInt(s)==2011 ? "\to" : "\tx") << std::endl;
  s = "MMXII"; std::cout << "MMXII\t" << romanToInt(s) << (romanToInt(s)==2012 ? "\to" : "\tx") << std::endl;
  s = "MMXIII"; std::cout << "MMXIII\t" << romanToInt(s) << (romanToInt(s)==2013 ? "\to" : "\tx") << std::endl;
  s = "MMXIV"; std::cout << "MMXIV\t" << romanToInt(s) << (romanToInt(s)==2014 ? "\to" : "\tx") << std::endl;
  s = "MMXV"; std::cout << "MMXV\t" << romanToInt(s) << (romanToInt(s)==2015 ? "\to" : "\tx") << std::endl;
  s = "MMXVI"; std::cout << "MMXVI\t" << romanToInt(s) << (romanToInt(s)==2016 ? "\to" : "\tx") << std::endl;
  s = "MMXVII"; std::cout << "MMXVII\t" << romanToInt(s) << (romanToInt(s)==2017 ? "\to" : "\tx") << std::endl;
  s = "MMXVIII"; std::cout << "MMXVIII\t" << romanToInt(s) << (romanToInt(s)==2018 ? "\to" : "\tx") << std::endl;
  s = "MMXIX"; std::cout << "MMXIX\t" << romanToInt(s) << (romanToInt(s)==2019 ? "\to" : "\tx") << std::endl;
  s = "MMXX"; std::cout << "MMXX\t" << romanToInt(s) << (romanToInt(s)==2020 ? "\to" : "\tx") << std::endl;
  s = "MCMLXXVI"; std::cout << "MCMLXXVI\t" << romanToInt(s) << (romanToInt(s)==1976 ? "\to" : "\tx") << std::endl;

  return 0;
}
