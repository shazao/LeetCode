/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

// Star: 8.8.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include "..\Profiler.h"

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
  public:
    virtual UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node) = 0; // Pure virtual, or Solutionx may not have data members.
};

// From LeetCode Discuss.
class Solution0 : public Solution {
  public:
    UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node) {
      if (!node) return node;
      auto cloned_node = label_node_map_.find(node->label);
      if (cloned_node == label_node_map_.end()) {
        UndirectedGraphNode * new_node = new UndirectedGraphNode(node->label);
        label_node_map_[node->label] = new_node;
        for (auto it=node->neighbors.begin(), e=node->neighbors.end(); it!=e; ++it)
          new_node->neighbors.push_back(cloneGraph(*it));
        return new_node;
      } else return cloned_node->second;
    }
  private:
    std::unordered_map<int, UndirectedGraphNode*> label_node_map_;
};

class Solution1 : public Solution {
  public:
    
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get an array.
  std::cout << "Please input the array: ";
  std::vector<int> iv;
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);
  std::cout << "The array you input is: ";
  for (auto itr=iv.begin(); itr!=iv.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    //solutions[si]->;
  }

  return 0;
}
