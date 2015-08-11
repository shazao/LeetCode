/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

// Star: 6.
// Info.: Boring.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int compareVersion(std::string version1, std::string version2) {

  while (version1.empty()==false && version2.empty()==false) {
    int v1 = 0;
    int v2 = 0;
    size_t p1 = version1.find('.');
    size_t p2 = version2.find('.');
    v1 = std::atoi(version1.substr(0, p1).c_str());
    v2 = std::atoi(version2.substr(0, p2).c_str());
    if (v1 > v2)
      return 1;
    else if (v1 < v2)
      return -1;

    if (p1 != std::string::npos)
      version1 = version1.substr(p1+1, std::string::npos);
    else
      version1 = "";
    if (p2 != std::string::npos)
      version2 = version2.substr(p2+1, std::string::npos);
    else
      version2 = "";
  }

  if (version1.empty()==true && version2.empty()==true)
    return 0;
  else if (version1.empty()==true && std::atoi(version2.substr(0, version2.find('.')).c_str())!=0)
    return -1;
  else if (version2.empty()==true && std::atoi(version1.substr(0, version1.find('.')).c_str())!=0)
    return 1;
  else
    return 0;
}

int main(int argc, char * argv[]) {

  if (argc != 3) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::string v1(argv[1]);
  std::string v2(argv[2]);

  std::cout << compareVersion(v1, v2) << std::endl;

  return 0;
}
