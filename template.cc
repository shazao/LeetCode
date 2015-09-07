/*

*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  int n = atoi(argv[1]);

  return 0;
}

  std::vector<int> iv;
  for (int i=1; i<argc; ++i)
    iv.push_back(std::atoi(argv[i]));
  std::cout << "\nOriginal vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";
  std::cout << std::endl;
