/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

// Star: 7.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Solution 0: Common method.
//int hammingWeight(uint32_t n) {
//  int count = 0;
//  int i = 0;
//  for (; i<32; ++i) {
//    if (n & 0x1)
//      ++ count;
//    n >>= 1;
//  }
//  return count;
//}

// Solution 1: More ingenious one(From <Sword at Offer>).
int hammingWeight(uint32_t n) {
  int count = 0;
  while (n) {
    ++ count;
    n = (n-1) & n;    // Count the right-most Bit 1.
  }
  return count;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  uint32_t n = atoi(argv[1]);
  printf("%u has %d 1's in binary.\n", n, hammingWeight(n));

}

// One line sulotion.
// return n > 0 ? n % 2 + hammingWeight(n/2) : 0;
