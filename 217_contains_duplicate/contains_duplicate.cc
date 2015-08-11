/*
Given an array of integers, find if the array contains any duplicates. Your function should return true 
if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

// Star: 6.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_set>

bool containsDuplicate(std::vector<int> & nums) {
  std::unordered_set<int> us;
  for (size_t i=0; i<nums.size(); ++i)
    if (us.find(nums[i]) != us.end())
      return true;
    else
      us.insert(nums[i]);
  return false;
}

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  for (int i=1; i<argc; ++i)
    iv.push_back(std::atoi(argv[i]));
  std::cout << "Original vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";

  std::cout << (containsDuplicate(iv)?"contains ":"doesn't contain ") << "duplicates." << std::endl;

  return 0;
}

// A C solution from LeetCode Discuss.
//struct Node
//{
//    int val;
//    struct Node *next;
//};
//
//struct Set
//{
//    int bucketSize;
//    struct Node **table;
//};
//
//void initSet(struct Set *set, int bucketSize)
//{
//    set->bucketSize = bucketSize;
//    set->table = malloc(sizeof(struct Node*) * bucketSize);
//    memset(set->table, 0, sizeof(struct Node*) * bucketSize);
//}
//
//bool addValue(struct Set *s, int val)
//{
//    int idx = val > 0 ? val : -val;
//    idx %= s->bucketSize;
//    struct Node *ptr = s->table[idx];
//    while(ptr != NULL)
//    {
//        if(ptr->val == val)
//        {
//            return false;
//        }
//
//        ptr = ptr->next;
//    }
//    ptr = malloc(sizeof(struct Node));
//    ptr->val = val;
//    ptr->next = s->table[idx];
//    s->table[idx] = ptr;
//    return true;
//}
//void releaseSet(struct Set *s)
//{
//    struct Node *ptr, *tmp;
//    for(int i = 0; i < s->bucketSize; ++i)
//    {
//        ptr = s->table[i];
//        while(ptr != NULL)
//        {
//            tmp = ptr;
//            ptr = ptr->next;
//            free(tmp);
//        }
//    }
//    free(s->table);
//    s->table = NULL;
//    s->bucketSize = 0;
//}
//bool containsDuplicate(int* nums, int numsSize) {
//    if(numsSize < 2)
//    {
//        return false;
//    }
//    struct Set set;
//    initSet(&set, numsSize / 2);
//    for(int i = 0; i < numsSize; ++i)
//    {
//        if(!addValue(&set, nums[i]))
//        {
//            releaseSet(&set);
//            return true;
//        }
//    }
//    releaseSet(&set);
//    return false;
//}
