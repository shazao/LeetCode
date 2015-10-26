/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

// Star: 6.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::string simplifyPath(std::string path) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::string simplifyPath(std::string path) {
      std::string simplified_path;
      std::vector<std::string> directorys;
      path = path.substr(1, std::string::npos);
      while (path.size() > 0) {
        std::string directory = path.substr(0, path.find("/"));
        if (directory == "..") {
          if (!directorys.empty())
            directorys.pop_back();
        } else if (directory != "." && directory.size()>0)
          directorys.push_back(directory);
        if (path.find("/") == std::string::npos)
          path.clear();
        else
          path = path.substr(path.find("/")+1, std::string::npos);
      }
      for (auto vi=directorys.begin(); vi!=directorys.end(); ++vi)
        simplified_path += "/" + *vi;
      return simplified_path.empty() ? "/" : simplified_path;
    }
};

// Take advantage of "std::getline", faster!
class Solution1 : public Solution {
  public:
    std::string simplifyPath(std::string path) {
      std::string simplified_path, directory;
      std::vector<std::string> directorys;
      std::stringstream path_stream(path);
      while (std::getline(path_stream, directory, '/')) {
        if (directory=="." || directory=="") continue;
        if (directory==".." && !directorys.empty())
          directorys.pop_back();
        else if (directory != "..")
          directorys.push_back(directory);
      }
      for (auto vi=directorys.begin(); vi!=directorys.end(); ++vi)
        simplified_path += "/" + *vi;
      return simplified_path.empty() ? "/" : simplified_path;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the path: ";
  std::string path;
  std::cin >> path;
  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The simlified path is: " << solutions[si]->simplifyPath(path) << std::endl << std::endl;
  }

  return 0;
}
